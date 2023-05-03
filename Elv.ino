#include "arduino.h"
#include "FSM.h"

FSM fsm(0);

void setup()
{ 
  pinMode(15, OUTPUT); pinMode(17, OUTPUT);
  digitalWrite(15, HIGH); digitalWrite(17, HIGH);
  
  fsm.Init();
  
}

void loop()
{
  fsm.Elevator();
}
