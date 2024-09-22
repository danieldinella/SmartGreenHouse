#include "../../Command/src/command.h"

// Funzione che inserisce in un buffer la stringa che rappresenta lo stato dell'oggetto irrigatore.
void int2stateIrrigator(char *buf, irrigator_type x)
{
  if (x == IrrigatorON)
  {
    sprintf(buf, "IrrigatorOn");
  }
  else if (x == IrrigatorOFF)
  {
    sprintf(buf, "IrrigatorOFF");
  }
  else
  {
    sprintf(buf, "change_pressure");
  }
}