#include <iostream>
#include <random>
#include <unistd.h>
#include "irrigator.h"
#include <string.h>

int main()
{
    auto tempo_iniziale = std::chrono::steady_clock::now();
    // Connessione a Redis
    redisContext *context = redisConnect("127.0.0.1", 6379);
    if (context == NULL || context->err)
    {
        if (context)
        {
            std::cerr << "Errore nella connessione a Redis: " << context->errstr << std::endl;
            redisFree(context);
        }
        else
        {
            std::cerr << "Impossibile connettersi a Redis." << std::endl;
        }
        exit(1);
    }

    Con2DB db1("localhost", "5433", "smartgreenhouse", "12345", "logdb_smartgreenhouse");

    int pid;

    /* init random number generator  */
    srand((unsigned)time(NULL));

    pid = getpid();

    printf("Start irrigator with pid %ld, ppid %ld \n",
            (long)pid, (long)getppid());

    /* init irrigator state */
    Irrigator irrigator = initIrrigator();

    // Sottoscrizione al canale
    redisReply *reply = (redisReply *)redisCommand(context, "SUBSCRIBE irrigatorChannel");
    freeReplyObject(reply);

    while (true)
    {
        irrigator_type state;
        pressure p;
        int countMessage = 0;

        while (countMessage < 2)
        {
            if (redisGetReply(context, (void **)&reply) != REDIS_OK)
            {
                std::cerr << "Errore nella ricezione del messaggio da Redis." << std::endl;
                exit(1);
            }
            if (reply->type == REDIS_REPLY_ARRAY && reply->elements == 3)
            {

                if (countMessage == 0)
                {
                    state = static_cast<irrigator_type>(atoi(reply->element[2]->str));
                }
                else if (countMessage == 1)
                {
                    p = static_cast<pressure>(atoi(reply->element[2]->str));
                }

                freeReplyObject(reply);
            }
            countMessage++;
        }
        const char *sms;
        if (rand() % 100 >= 5)
        {
            sms = "ok";
            if (state == change_pressure)
            {
                irrigator.setPressure(p);
            }
            irrigator.setState(state);
            auto tempo_corrente = std::chrono::steady_clock::now();
            auto tempo_trascorso = std::chrono::duration_cast<std::chrono::milliseconds>(tempo_corrente - tempo_iniziale).count();
            log2devicedb(db1, irrigator.getId(), pid, irrigator.getState(), irrigator.getPressure(), tempo_trascorso);
        }
        else
        {
            sms = "Comando fallito";
        }
        sleep(5);
        redisContext *context2 = redisConnect("127.0.0.1", 6379);
        redisReply *secondReply = (redisReply *)redisCommand(context2, "PUBLISH rispostaChannel %s", sms);
        if (secondReply != NULL)
        {
            freeReplyObject(secondReply);
        }
        else
        {
            std::cerr << "Errore nell'invio del messaggio a Redis." << std::endl;
        }
    }

    redisFree(context);
    return 0;
}
