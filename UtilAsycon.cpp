#include "UtilAsycon.h"

int TimeBreak_ON = 400;
int TimeBreak_OFF = 500;
int TimeSeguro = 800;
int tw = 200;

int SensorSeguroP1 = 0;
int SensorSeguroP2 = 0;
int SensorSeguroP3 = 0;
int SensorSeguroP4 = 0;

UtilAsycon::UtilAsycon(byte pin){
    Init();
}

void UtilAsycon::Init(){
    pinMode(BreakMotorA,OUTPUT);
    pinMode(BreakMotorB,OUTPUT);
    digitalWrite(BreakMotorA,HIGH);
    digitalWrite(BreakMotorB,HIGH);
    //
    pinMode(Seguro_1A, OUTPUT); pinMode(Seguro_1B, OUTPUT);
    pinMode(Seguro_2A, OUTPUT); pinMode(Seguro_2B, OUTPUT);
  
    pinMode(Seguro_3A, OUTPUT); pinMode(Seguro_3B, OUTPUT);
    pinMode(Seguro_4A, OUTPUT); pinMode(Seguro_4B, OUTPUT);
    //
    pinMode(Lampara_B1,OUTPUT);
    pinMode(Lampara_B2,OUTPUT);
    pinMode(Lampara_B3,OUTPUT);
    pinMode(Lampara_B4,OUTPUT);
    //
    pinMode(Sensor_Seguro_P1,INPUT);
    pinMode(Sensor_Seguro_P2,INPUT);
    pinMode(Sensor_Seguro_P3,INPUT);
    pinMode(Sensor_Seguro_P4,INPUT);
}

void UtilAsycon::stp(){
    digitalWrite(Lampara_B4,HIGH);
    digitalWrite(Lampara_B3,HIGH);
    digitalWrite(Lampara_B2,HIGH);
    digitalWrite(Lampara_B1,HIGH);
}

int UtilAsycon::SensorSeguro(){
  
    SensorSeguroP1 = digitalRead(Sensor_Seguro_P1);
    SensorSeguroP2 = digitalRead(Sensor_Seguro_P2);
    SensorSeguroP3 = digitalRead(Sensor_Seguro_P3);
    SensorSeguroP4 = digitalRead(Sensor_Seguro_P4);

    if(SensorSeguroP4 == HIGH && SensorSeguroP3 == HIGH){
         if(SensorSeguroP2 == HIGH && SensorSeguroP1 == HIGH){
             return 1;
         }else{
             Lampara(5);
             return 0;
         }
    }else
    {
        Lampara(5);
        return 0;
    }
    
}
void UtilAsycon::Seguro_Pisos(int c){

        if(c == 1){
            delay(tw);
            digitalWrite(Seguro_3B, HIGH); digitalWrite(Seguro_3A, LOW);
            delay(TimeSeguro);
            digitalWrite(Seguro_3B, LOW); digitalWrite(Seguro_3A, LOW);
            delay(tw);
            digitalWrite(Seguro_4B, HIGH); digitalWrite(Seguro_4A, LOW);
            delay(TimeSeguro);
            digitalWrite(Seguro_4B, LOW); digitalWrite(Seguro_4A, LOW);
            delay(tw);
            digitalWrite(Seguro_1B, HIGH); digitalWrite(Seguro_1A, LOW);
            delay(TimeSeguro);
            digitalWrite(Seguro_1B, LOW); digitalWrite(Seguro_1A, LOW);
            delay(tw);
        }
        if(c == 2){
            delay(tw);
            digitalWrite(Seguro_3A, HIGH); digitalWrite(Seguro_3B, LOW);
            delay(TimeSeguro);
            digitalWrite(Seguro_3A, LOW); digitalWrite(Seguro_3B, LOW);
            delay(tw);
            digitalWrite(Seguro_4A, HIGH); digitalWrite(Seguro_4B, LOW);
            delay(TimeSeguro);
            digitalWrite(Seguro_4A, LOW); digitalWrite(Seguro_4B, LOW);
            delay(tw);
            digitalWrite(Seguro_1A, HIGH); digitalWrite(Seguro_1B, LOW);
            delay(TimeSeguro);
            digitalWrite(Seguro_1A, LOW); digitalWrite(Seguro_1B, LOW);
            delay(tw);
        }
    
}

void UtilAsycon::Lampara(int p){
    if(p == 0){
        digitalWrite(Lampara_B4,HIGH);
        digitalWrite(Lampara_B3,HIGH);
        digitalWrite(Lampara_B2,HIGH);
        digitalWrite(Lampara_B1,HIGH);
    }
    if(p == 1){
        digitalWrite(Lampara_B1,LOW);
        digitalWrite(Lampara_B4,HIGH);
        digitalWrite(Lampara_B3,HIGH);
        digitalWrite(Lampara_B2,HIGH);
    }
    if(p == 2){
        digitalWrite(Lampara_B2,LOW);
        digitalWrite(Lampara_B3,HIGH);
        digitalWrite(Lampara_B4,HIGH);
        digitalWrite(Lampara_B1,HIGH);
    }
    if(p == 3){
        digitalWrite(Lampara_B3,LOW);
        digitalWrite(Lampara_B4,HIGH);
        digitalWrite(Lampara_B2,HIGH);
        digitalWrite(Lampara_B1,HIGH);
    }
    if(p == 4){
        digitalWrite(Lampara_B4,LOW);
        digitalWrite(Lampara_B3,HIGH);
        digitalWrite(Lampara_B2,HIGH);
        digitalWrite(Lampara_B1,HIGH);        
    }
    if(p == 5){
      digitalWrite(Lampara_B4,HIGH);
      digitalWrite(Lampara_B1,HIGH);
      digitalWrite(Lampara_B2,HIGH);
      digitalWrite(Lampara_B3,HIGH);
    }

    if(p == 6){
      digitalWrite(Lampara_B4,LOW);
      digitalWrite(Lampara_B1,LOW);
      digitalWrite(Lampara_B2,LOW);
      digitalWrite(Lampara_B3,LOW);
    }
}

void UtilAsycon::Break(int time){

    digitalWrite(BreakMotorA,LOW);
    delay(time);
    digitalWrite(BreakMotorA,HIGH);
    //delay(TimeBreak);
}

void UtilAsycon::UnBreak(){
    digitalWrite(BreakMotorB,LOW);
    delay(TimeBreak_OFF);
    digitalWrite(BreakMotorB,HIGH);
    //delay(TimeBreak);
}

void UtilAsycon::ReadSensor(){ 

    int S1 = digitalRead(30);
    int S2= digitalRead(28);
    int S3 = digitalRead(26);
    int S4 = digitalRead(24);
    
    Serial.print("Sensor 1: ");
    Serial.print(S1);
    Serial.print("  Sensor 2: ");
    Serial.print(S2);
    Serial.print("||--");
    Serial.print("  Sensor 3: ");
    Serial.print(S3);
    Serial.print("  Sensor 4: ");
    Serial.print(S4);
    Serial.println("  --||--");
    
}
