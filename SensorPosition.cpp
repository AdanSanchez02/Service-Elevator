#include "SensorPosition.h"
#include "CallButton.h"
#include "UtilAsycon.h"

UtilAsycon asy(0);
CallButton Botonera(0);

int SENSOR_STATE_P1_A = 0;
int SENSOR_STATE_P1_B = 0;

int SENSOR_STATE_P2_A = 0;
int SENSOR_STATE_P2_B = 0;

int SENSOR_STATE_P3_A = 0;
int SENSOR_STATE_P3_B = 0;

int SENSOR_STATE_P4_A = 0;
int SENSOR_STATE_P4_B = 0;

int SENSOR_STATE_PF_A = 0;
int SENSOR_STATE_PF_B = 0;

int TimeFrenoInicial = 500;
int TimeSpace = 350;

SensorPosition::SensorPosition(byte pin){

}

void SensorPosition::Init(){
    pinMode(POSITIOM_PISO4_A,INPUT);
    pinMode(POSITIOM_PISO4_B,INPUT);

    pinMode(POSITIOM_PISO3_A,INPUT);
    pinMode(POSITIOM_PISO3_B,INPUT);

    pinMode(POSITIOM_PISO2_A,INPUT);
    pinMode(POSITIOM_PISO2_B,INPUT);

    pinMode(POSITIOM_PISO1_A,INPUT);
    pinMode(POSITIOM_PISO1_B,INPUT);

    pinMode(POSITIOM_LIM_A ,INPUT);
    pinMode(POSITIOM_LIM_B ,INPUT);
}

int SensorPosition::Position_P3(){
    int button = Botonera.CheckPress();      
    if(button == 5){
        return 2;
    } 

    SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
    SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
    if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
      return 1;
    }
    
    SENSOR_STATE_P3_A = digitalRead(POSITIOM_PISO3_A);
    SENSOR_STATE_P3_B = digitalRead(POSITIOM_PISO3_B);
   
    if(SENSOR_STATE_P3_A == HIGH || SENSOR_STATE_P3_B == HIGH){
        delay(TimeSpace);
        asy.Break(TimeFrenoInicial);
        
        while(true){
            SENSOR_STATE_P3_A = digitalRead(POSITIOM_PISO3_A);
            SENSOR_STATE_P3_B = digitalRead(POSITIOM_PISO3_B);
            if(SENSOR_STATE_P3_A == HIGH || SENSOR_STATE_P3_B == HIGH){
              return 1;
              break;
            }
            
            SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
            SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
            if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
              return 1;
              break;
            }
            
            button = Botonera.CheckPress();    
            if(button == 5){
                return 2;
                break;
            }
        }
        
    }
    else{
        return 0;
    }
}

int SensorPosition::Position_P2(){
    int button = Botonera.CheckPress();    
    if(button == 5){
        return 2;
    }

    SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
    SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
    if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
      return 1;
    }
    
    SENSOR_STATE_P2_A = digitalRead(POSITIOM_PISO2_A);
    SENSOR_STATE_P2_B = digitalRead(POSITIOM_PISO2_B);
    
    if(SENSOR_STATE_P2_A == HIGH || SENSOR_STATE_P2_B == HIGH){
        delay(TimeSpace);
        asy.Break(TimeFrenoInicial);
        
        while(true){
            SENSOR_STATE_P2_A = digitalRead(POSITIOM_PISO2_A);
            SENSOR_STATE_P2_B = digitalRead(POSITIOM_PISO2_B);
            if(SENSOR_STATE_P2_A == HIGH || SENSOR_STATE_P2_B == HIGH){
                return 1;
                break;
            }

            SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
            SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
            if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
              return 1;
              break;
            }
            
            button = Botonera.CheckPress();    
            if(button == 5){
                return 2;
                break;
            }
        }
        
    }
    else{
        return 0;
    }
}

int SensorPosition::Position_P1(){
    int button = Botonera.CheckPress();    
    if(button == 5){
        return 2;
    }

    SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
    SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
    if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
      return 1;
    }

    SENSOR_STATE_P1_A = digitalRead(POSITIOM_PISO1_A);
    SENSOR_STATE_P1_B = digitalRead(POSITIOM_PISO1_B);
    
    if(SENSOR_STATE_P1_A == HIGH || SENSOR_STATE_P1_B == HIGH){
        //delay(350);
        asy.Break(TimeFrenoInicial + 70);
      
        while(true){
            SENSOR_STATE_P1_A = digitalRead(POSITIOM_PISO1_A);
            SENSOR_STATE_P1_B = digitalRead(POSITIOM_PISO1_B);
            if(SENSOR_STATE_P1_A == HIGH || SENSOR_STATE_P1_B == HIGH){
                return 1;
                break;
            }

            SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
            SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
            if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
              return 1;
              break;
            }
            
            button = Botonera.CheckPress();    
            if(button == 5){
                return 2;
                break;
            }
        }
        
    }
    else{
        return 0;
    }
}

int SensorPosition::Position_P4(){
    int button = Botonera.CheckPress();    
    if(button == 5){
        return 2;
    }

    SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
    SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
    if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
      return 1;
    }
    
    SENSOR_STATE_P4_A = digitalRead(POSITIOM_PISO4_A);
    SENSOR_STATE_P4_B = digitalRead(POSITIOM_PISO4_B);
    
    if(SENSOR_STATE_P4_A == HIGH || SENSOR_STATE_P4_B == HIGH){
        delay(TimeSpace);

        while(true){
            SENSOR_STATE_P4_A = digitalRead(POSITIOM_PISO4_A);
            SENSOR_STATE_P4_B = digitalRead(POSITIOM_PISO4_B);
            if(SENSOR_STATE_P4_A == HIGH || SENSOR_STATE_P4_B == HIGH){
                return 1;
                break;
            }

            SENSOR_STATE_PF_A = digitalRead(POSITIOM_LIM_A);
            SENSOR_STATE_PF_B = digitalRead(POSITIOM_LIM_B);
            if(SENSOR_STATE_PF_A == HIGH || SENSOR_STATE_PF_B == HIGH){
              return 1;
              break;
            }
            
            button = Botonera.CheckPress();    
            if(button == 5){
                return 2;
                break;
            }
        }
        
    }
    else{
        return 0;
    }
}

int SensorPosition::ReadPosition(){

    SENSOR_STATE_P1_A = digitalRead(POSITIOM_PISO1_A);
    SENSOR_STATE_P1_B = digitalRead(POSITIOM_PISO1_B);
    SENSOR_STATE_P2_A = digitalRead(POSITIOM_PISO2_A);
    SENSOR_STATE_P2_B = digitalRead(POSITIOM_PISO2_B);
    SENSOR_STATE_P3_A = digitalRead(POSITIOM_PISO3_A);
    SENSOR_STATE_P3_B = digitalRead(POSITIOM_PISO3_B);
    SENSOR_STATE_P4_A = digitalRead(POSITIOM_PISO4_A);
    SENSOR_STATE_P4_B = digitalRead(POSITIOM_PISO4_B);

    if(SENSOR_STATE_P1_A == HIGH || SENSOR_STATE_P1_B == HIGH){
        return 1;
    }else{
        if(SENSOR_STATE_P2_A == HIGH || SENSOR_STATE_P2_B == HIGH){
            return 2;
        }else{
            if(SENSOR_STATE_P3_A == HIGH || SENSOR_STATE_P3_B == HIGH){
                return 3;
            }else{
                if(SENSOR_STATE_P4_A == HIGH || SENSOR_STATE_P4_B == HIGH){
                    return 4;
                }else{
                    return 0; 
                }                
            }
        }
    }
}
