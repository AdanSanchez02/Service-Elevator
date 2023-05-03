#include "CallButton.h"

int BUTTON_STATE_P4 = 0;
int BUTTON_STATE_P3 = 0;
int BUTTON_STATE_P2 = 0;
int BUTTON_STATE_PB = 0;
int BUTTON_STATE_EME =0;

CallButton::CallButton(byte pin){
    Init();
}

void CallButton::Init(){
    pinMode(CALL_EMERGENCY, INPUT);

    pinMode(CALL_STEP_P4,INPUT);
    pinMode(CALL_STEP_P3,INPUT);
    pinMode(CALL_STEP_P2,INPUT);
    pinMode(CALL_STEP_PB,INPUT);

    pinMode(POSITION_SP_1,INPUT);
    pinMode(POSITION_SP_2,INPUT);
    pinMode(POSITION_SP_3,INPUT);
    pinMode(POSITION_SP_4,INPUT);
}

bool CallButton::Check_Emergency(){
    BUTTON_STATE_EME = digitalRead(CALL_EMERGENCY);
    BUTTON_STATE_P4 = digitalRead(CALL_STEP_P4);
    if (BUTTON_STATE_P4 == HIGH && BUTTON_STATE_EME == HIGH) {
        return true;
    }
    else{
        return false;
    }
}

int CallButton::Check_SP(){ // MANDAR A PISO
    BUTTON_STATE_P4 = digitalRead(POSITION_SP_4);
    BUTTON_STATE_P3 = digitalRead(POSITION_SP_3);
    BUTTON_STATE_P2 = digitalRead(POSITION_SP_2);
    BUTTON_STATE_PB = digitalRead(POSITION_SP_1);
    BUTTON_STATE_EME = digitalRead(CALL_EMERGENCY);

    if (BUTTON_STATE_P4 == HIGH) {
        return 4;
    }
    else{
        if(BUTTON_STATE_P3 == HIGH){
            return 3;
        }
        else{
            if(BUTTON_STATE_P2 == HIGH){
                return 2;
            }
            else{
                if(BUTTON_STATE_PB == HIGH){
                    return 1;
                }
                else{
                    if(BUTTON_STATE_EME == HIGH){
                            return 5;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
}

int CallButton::CheckPress(){ //LLAMADO A PISO
    BUTTON_STATE_P4 = digitalRead(CALL_STEP_P4);
    BUTTON_STATE_P3 = digitalRead(CALL_STEP_P3);
    BUTTON_STATE_P2 = digitalRead(CALL_STEP_P2);
    BUTTON_STATE_PB = digitalRead(CALL_STEP_PB);
    BUTTON_STATE_EME = digitalRead(CALL_EMERGENCY);

    if (BUTTON_STATE_P4 == HIGH) {
        return 4;
    }
    else{
        if(BUTTON_STATE_P3 == HIGH){
            return 3;
        }
        else{
            if(BUTTON_STATE_P2 == HIGH){
                return 2;
            }
            else{
                if(BUTTON_STATE_PB == HIGH){
                    return 1;
                }
                else{
                    if(BUTTON_STATE_EME == HIGH){
                            return 5;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
}
