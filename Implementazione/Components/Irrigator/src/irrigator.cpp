#include "irrigator.h"

// Costruttore della classe Irrigator.
Irrigator::Irrigator(int id, irrigator_type state, pressure p) : id(id), state(state), p(p){}

// Funzione per ottenere lo stato corrente del irrigatore.
irrigator_type Irrigator::getState() const
{
    return state;
}

// Funzione per ottenere l'ID dell'irrigatore.
int Irrigator::getId() const
{
    return id;
}

// Funzione per impostare manualmente lo stato dell'irrigatore a IrrigatorON.
void Irrigator::setState()
{
    state = IrrigatorON;
}

// Funzione per impostare manualmente lo stato dell'irrigatore con il valore passato come argomento.
void Irrigator::setState(irrigator_type newState)
{
    state = newState;
}

// Funzione per ottenere la pressione dell'irrigatore.
pressure Irrigator::getPressure()
{
    return p;
}

// Funzione per settare manualmente la pressione dell'irrigatore con il valore passato come argomento.
void Irrigator::setPressure(pressure newP)
{
    p = newP;
}
