#include <Arduino.h>
class PullOut {
  
  private:
    byte pin;
    
  public:
    PullOut(byte pin);
    void init();
    void on();
    void off();
};
