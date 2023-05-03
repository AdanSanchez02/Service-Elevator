#include <Arduino.h>

#define Sensor_Seguro_P1 30
#define Sensor_Seguro_P2 28
#define Sensor_Seguro_P3 26
#define Sensor_Seguro_P4 24

#define Seguro_1A 20
#define Seguro_1B 21
#define Seguro_2A 4
#define Seguro_2B 5
#define Seguro_3A 7
#define Seguro_3B 6
#define Seguro_4A 2
#define Seguro_4B 14


#define Lampara_B4 11 
#define Lampara_B3 10 // 11 por 16
#define Lampara_B2 9
#define Lampara_B1 8

#define BreakMotorA 18
#define BreakMotorB 19

class UtilAsycon {
  
  private:
    byte pin;
    
  public:
    UtilAsycon(byte pin);
    void Init();
    void Break(int time);
    void UnBreak();
    void Seguro_Pisos(int c);
    void Lampara(int p);
    int SensorSeguro();
    void stp();
    void ReadSensor();
};
