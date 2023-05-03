#include <Arduino.h>
class AlternMotor {
  
  private:
    byte pin;
    
  public:
    AlternMotor(byte pin);
    void InitMotor();
    void Forward();
    void Backward();
};
