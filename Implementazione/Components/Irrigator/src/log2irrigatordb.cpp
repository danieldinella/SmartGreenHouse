#include "irrigator.h"
#include <cstring>

// Funzione per registrare le informazioni dell'irrigatore nel database.
void log2devicedb(Con2DB db1, int id, int pid, irrigator_type state, pressure p, int64_t tempo_trascorso)
{
  // Dichiarazioni di variabili locali
  PGresult *res;
  char cstate[20];
  char sqlcmd[1000];
  char n[20];
  char timeString[25];

  // Converti lo stato dell'irrigatore in una rappresentazione di stringa.
  int2stateIrrigator(cstate, state);

  // Converti il nome dell'irrigatore in una rappresentazione di stringa.
  pressureToString(p);
  strcpy(n, pressureToString(p));

  // Ottieni una stringa rappresentante il timestamp corrente.
  timeFlies(timeString);

  // Inizia una transazione nel database PostgreSQL.
  sprintf(sqlcmd, "BEGIN");
  res = db1.ExecSQLcmd(sqlcmd);
  PQclear(res);

  // Esegui l'inserimento dei dati nel database.
  sprintf(sqlcmd,
          "INSERT INTO Device VALUES (%ld, %d, '%s', '%s', %d, %d, '%s') ON CONFLICT DO NOTHING",
          tempo_trascorso,
          id,
          cstate,
          n,
          p,
          pid,
          timeString);

  // Esegui il comando SQL e verifica se ci sono conflitti.
  res = db1.ExecSQLcmd(sqlcmd);
  PQclear(res);

  // Concludi la transazione nel database PostgreSQL.
  sprintf(sqlcmd, "COMMIT");
  res = db1.ExecSQLcmd(sqlcmd);
  PQclear(res);
}
