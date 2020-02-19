
boolean debug = false;
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


  if (debug == true) {
    printValuesBME();
  }
}
