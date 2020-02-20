#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 64

#define SERIAL_BUFFER_SIZE 256

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//DATAS-------------------------------------------------------------------
int temperature;
int pressure;
int altitude;
int humidity;

uint8_t inBuffer [LED_COUNT * 3 + 1];
boolean isBufferValide = false;

void setup() {
  Serial.begin(115200);

  Serial.println("bme > START");
  initBME280();
  Serial.println("bme > OK");

  Serial.println("weather start");
  initWeatherShield();
  Serial.println("weather > OK");
  // put your setup code here, to run once:
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  int index = 0;
  for (int c = 1; c < (LED_COUNT * 3) + 1; c += 3) {
    strip.setPixelColor(index, strip.Color(255, 255, 0));
    index++;
  }
  strip.show();
  Serial.println("ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  //phare();
  if (isBufferValide) {
    updateLed(inBuffer);
    isBufferValide = false;
  }


  //runBME();
  runWeather();
}

void serialEvent() {
  if (Serial.available()) {
    Serial.readBytes(inBuffer, LED_COUNT * 3 + 1);
    if (inBuffer[0] == 0x01) {
      isBufferValide = true;
    }
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
