#include <Arduino.h>

class FSM {
  
  private:
    byte pin;
    
  public:
    FSM(byte pin);
    void Init();
    void Send_Position();
    int Ver_Pos(int a);
    int SelectionMove(int x);
    void Stop_Emergency();
    void Return_Emergency();
    void Elevator();
};
