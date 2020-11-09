#include <heltec.h>

void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, true /*LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, 470E6 /**/);
}

void loop() {
  // put your main code here, to run repeatedly:
}
