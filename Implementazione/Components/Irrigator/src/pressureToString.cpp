#include "irrigator.h"

// Funzione che ritorna la stringa rappresentate la pressione passata come argomento
const char* pressureToString(pressure p)
{
  switch (p)
  {
    case LOW:
      return "LOW";
    case MEDIUM:
      return "MEDIUM";
    case HIGH:
      return "HIGH";
    default:
      return "UNKNOWN_PRESSURE";
  }
}
