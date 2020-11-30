#include <heltec.h>

const bool DISPLAY_ENABLED = true;
const bool LORA_ENABLED = false;
const int64_t LORA_FREQUENCY = 470E6;
const bool LORA_POWER_BOOST = false;
const bool SERIAL_ENABLED = true;

int loop_count = 0;

void setup() {
  Heltec.begin(
      DISPLAY_ENABLED,
      LORA_ENABLED,
      SERIAL_ENABLED,
      LORA_POWER_BOOST,
      LORA_FREQUENCY);
  delay(200);
}

void loop() {
  loop_count += 1;
  Serial.printf("[%i] Hello from Daisy!!\n", loop_count);
  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "Hello from Daisy");
  Heltec.display->display();
  delay(1000);
}
