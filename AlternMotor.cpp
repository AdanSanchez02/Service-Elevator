#include "AlternMotor.h"
#include "PullOut.h"
#include "UtilAsycon.h"

#define RELE_MOTOR_A 15
#define RELE_MOTOR_B 17


AlternMotor::AlternMotor(byte pin) {
  InitMotor();
}

PullOut Motor1(RELE_MOTOR_A);
PullOut Motor2(RELE_MOTOR_B);

void AlternMotor::InitMotor() {
    Motor1.on();
    Motor2.on();
}

void AlternMotor::Forward(){
    Motor1.off();
    Motor2.on();
}


void AlternMotor::Backward(){
    Motor1.on();
    Motor2.off();
}
