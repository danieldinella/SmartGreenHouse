#include "irrigator.h"
#include <cstdlib>

// Funzione che inizializza l'oggetto Irrigatore.
Irrigator initIrrigator()
{
    Irrigator irrigator(rand(), static_cast<irrigator_type>(rand() % 2), static_cast<pressure>(rand() % 3));
    return irrigator;
}