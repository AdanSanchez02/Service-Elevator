#include "PullOut.h"

PullOut::PullOut(byte pin) {
  this->pin = pin;
  init();
}

void PullOut::init() {
  pinMode(pin, OUTPUT);
  on();//
}

void PullOut::on() {
  digitalWrite(pin, HIGH);
}

void PullOut::off() {
  digitalWrite(pin, LOW);
}
