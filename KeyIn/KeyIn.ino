// use digispark board & library

#include "DigiKeyboard.h"

// key input in pin 0, led indicator in pin 1

# define Led 1
# define SwitchIn 0

void setup() {
  // initialize pin mode
  pinMode(Led, OUTPUT);
  pinMode(SwitchIn, INPUT_PULLUP);
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  delay(30);
  if (!digitalRead(SwitchIn)){
    digitalWrite(Led, HIGH);
    // set press key is ctrl + F7/ MOD_CONTROL_RIGHT & KEY_F7
    DigiKeyboard.sendKeyPress(KEY_F7, MOD_CONTROL_RIGHT);
    DigiKeyboard.sendKeyStroke(0);
    // check input switch is release ...
    do{
      delay(100);
    }while(!digitalRead(SwitchIn));
  }
  else{
    digitalWrite(Led, LOW);
  }
}
