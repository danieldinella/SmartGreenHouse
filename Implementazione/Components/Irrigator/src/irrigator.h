#ifndef IRRIGATOR_H
#define IRRIGATOR_H

#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <hiredis/hiredis.h>
#include <string>
#include "pgsql.h"

// Enumerazione che rappresenta i possibili stati dell'irrigatore.
typedef enum
{
    IrrigatorON,
    IrrigatorOFF,
    change_pressure,
} irrigator_type;

// Enumerazione che rappresenta i possibili stati della pressione.
typedef enum
{
    LOW,
    MEDIUM,
    HIGH,
} pressure;

// Dichiarazione della classe Irrigator.
class Irrigator
{
private:
    // Variabile che rappresenta l'identificatore dell'irrigatore.
    int id;
    
    // Variabile di stato dell'irrigatore.
    irrigator_type state;

    //Variabile che rappresenta la pressione dell'irrigatore.
    pressure p;

public:
    // Costruttore della classe Irrigator.
    Irrigator(int id, irrigator_type state, pressure p);

    // Funzione per ottenere lo stato corrente dell'irrigatore.
    irrigator_type getState() const;

    // Funzione per ottenere l'ID dell'irrigatore.
    int getId() const;

    // Funzione per impostare manualmente lo stato dell'irrigatore a IrrigatorON.
    void setState();

    // Funzione per impostare manualmente lo stato dell'irrigatore con il valore passato come argomento.
    void setState(irrigator_type newState);

    // Funzione per settare manualmente la pressione dell'irrigatore.
    void setPressure(pressure newP);

    // Funzione per ottenere la pressione attuale dell'irrigatore.
    pressure getPressure();
};

Irrigator initIrrigator();
void log2devicedb(Con2DB db1, int id, int pid, irrigator_type state, pressure p, int64_t tempo_trascorso);
void int2stateIrrigator(char *cstate, irrigator_type);
const char* pressureToString(pressure p);
void timeFlies(char *buf);
#endif
