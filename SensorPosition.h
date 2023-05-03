#include <Arduino.h>

#define POSITIOM_LIM_A 22
#define POSITIOM_LIM_B 39

#define POSITIOM_PISO1_A 23
#define POSITIOM_PISO1_B 25

#define POSITIOM_PISO2_A 27
#define POSITIOM_PISO2_B 29

#define POSITIOM_PISO3_A 46
#define POSITIOM_PISO3_B 33

#define POSITIOM_PISO4_A 35
#define POSITIOM_PISO4_B 37

class SensorPosition {
  
  private:
    byte pin;
    
  public:
    SensorPosition(byte pin);
    void Init();
    int Position_P1();
    int Position_P2();
    int Position_P3();
    int Position_P4();
    int ReadPosition();
    void Check_Return();
    
};
