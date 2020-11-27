#include <heltec.h>

const bool DISPLAY_ENABLED = true;
const bool LORA_ENABLED = true;
const int64_t LORA_FREQUENCY = 470E6;
const bool LORA_POWER_BOOST = true;
const bool SERIAL_ENABLED = true;

void setup() {
  Heltec.begin(
      DISPLAY_ENABLED,
      LORA_ENABLED,
      SERIAL_ENABLED,
      LORA_POWER_BOOST,
      LORA_FREQUENCY);
}

void loop() {
  // put your main code here, to run repeatedly:
}
