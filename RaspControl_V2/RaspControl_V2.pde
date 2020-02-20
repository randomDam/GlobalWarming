import processing.serial.*;

Serial myPort;
int lf = 10;

boolean isSerialOn=true;

void setup() 
{
    size(800, 400);
    initLED();
	initMeteo();	

    if (isSerialOn && Serial.list().length>0) {
        myPort = new Serial(this, "/dev/ttyACM1", 115200);
        myPort.bufferUntil(lf);
    }
}

void draw() {
    background(0);
    runLED();
    
    drawMeteo();
}
