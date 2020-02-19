#include <Adafruit_NeoPixel.h>

#define LED_PIN    3
#define LED_COUNT 64
#define SERIAL_BUFFER_SIZE 256

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint8_t inBuffer [LED_COUNT * 3 + 1];
boolean isBufferValide = false;


void initLED() {
  // put your setup code here, to run once:
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loopLED() {
  if (isBufferValide) {
    updateLed(inBuffer);
    isBufferValide = false;
  }
}

void updateLed(uint8_t * buff) {
  int index = 0;
  for (int c = 1; c < (LED_COUNT * 3) + 1; c += 3) {
    strip.setPixelColor(index, strip.Color(*(buff + c), *(buff + c + 1), *(buff + c + 2)));
    index++;
  }
  strip.show();
  //Serial.write(buff,(LED_COUNT * 3)+1);
}

void serialEvent() {
  if (Serial.available()) {
    Serial.readBytes(inBuffer, LED_COUNT * 3 + 1);
    if (inBuffer[0] == 0x01) {
      isBufferValide = true;
    }
  }
}
