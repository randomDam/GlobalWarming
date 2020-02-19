
boolean debug = false;
long lastTime = 0;
//DATAS-------------------------------------------------------------------
int temperature;
int pressure;
int altitude;
int humidity;

//-------------------------------------------------------------------------
//  SETUP
//-------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("led > START");
  initLED();
  Serial.println("led > OK");

  Serial.println("bme > START");
  initBME280();
  Serial.println("bme > OK");

  Serial.println("weather start");
  initWeatherShield();
  Serial.begin("weather > OK");

  Serial.println("ready");
}

//-------------------------------------------------------------------------
//  LOOP
//-------------------------------------------------------------------------
void loop() {
  //led
  loopLED();

  //Bme
  runBME();

  //WeatherShield
  runWeather();

  delay(10);

  if (millis() - lastTime >= 1000) {
    lastTime += 1000;

    if (debug == true) {
      printValuesBME_DEBUG();
      printWeather_Debug();
      
    } else {
      printValuesBME();
      printWeather();

      Serial.println();
    }
  }
}
