#include <Arduino.h>

#define CALL_STEP_P4 44
#define CALL_STEP_P3 45
#define CALL_STEP_P2 43
#define CALL_STEP_PB 32

#define CALL_EMERGENCY 34

#define POSITION_SP_1 42
#define POSITION_SP_2 40
#define POSITION_SP_3 38
#define POSITION_SP_4 36

class CallButton {
  
  private:
    byte pin;
    
  public:
    CallButton(byte pin);
    void Init();
    int CheckPress();
    int Check_SP();
    bool Check_Emergency();
};
