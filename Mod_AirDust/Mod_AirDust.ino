bool debug=false;

// INCLUDE
#include <Wire.h>
#include <SPI.h>
#include"AirQuality.h"
#include"Arduino.h"
#include <Adafruit_Sensor.h>
// GLOBAL VARIABLE

AirQuality airqualitysensor;
int current_quality = -1;
int measurePin = A1; // V0 (Pin 5) to Arduino A0
int ledPower = 12;   // PIN 3 (LED) to Arduino D2

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(115200);
 
  pinMode(ledPower, OUTPUT);
  //airqualitysensor.init(A0);

  Serial.println();
}


void loop() {
  Serial.println("-------------");
  
  /*
  current_quality = airqualitysensor.slope();
  
  if (current_quality >= 0)// if a valid data returned.
  {
    if (current_quality == 0)
      Serial.println("High pollution! Force signal active");
    else if (current_quality == 1)
      Serial.println("High pollution!");
    else if (current_quality == 2)
      Serial.println("Low pollution!");
    else if (current_quality == 3)
      Serial.println("Fresh air");
  }
  digitalWrite(ledPower, LOW); // power on the LED
  delayMicroseconds(samplingTime);
  */

  //----------------------------------------------------------
  //DUST
  //----------------------------------------------------------
  voMeasured = analogRead(measurePin); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH); // turn the LED off
  delayMicroseconds(sleepTime);

  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (5.0 / 1024.0);

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  dustDensity = 0.17 * calcVoltage - 0.1;

  if (debug == true) {
    Serial.print("GP2Y1010AU0F_vo_raw:");
    Serial.print(voMeasured);

    Serial.print(";GP2Y1010AU0F_voltage:");
    Serial.print(calcVoltage);

    Serial.print(";GP2Y1010AU0F_dust_density:");
    Serial.println(dustDensity); // unit: mg/m3
  }

}

ISR(TIMER2_OVF_vect)
{
  if (airqualitysensor.counter == 122) //set 2 seconds as a detected duty
  {
    airqualitysensor.last_vol = airqualitysensor.first_vol;
    airqualitysensor.first_vol = analogRead(A0);
    airqualitysensor.counter = 0;
    airqualitysensor.timer_index = 1;
    PORTB = PORTB ^ 0x20;
  }
  else
  {
    airqualitysensor.counter++;
  }
}
