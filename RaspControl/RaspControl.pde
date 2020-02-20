import processing.serial.*;

Serial myPort;
int lf = 10;

boolean isSerialOn=false;

void setup() 
{
    size(800, 400, P2D);
    initLED();
	initMeteo();	

    if (isSerialOn && Serial.list().length>0) {
        String portName = Serial.list()[1];
        myPort = new Serial(this, portName, 115200);
        myPort.bufferUntil(lf);
    }
    initLED();
}

void draw() {
    background(0);
    runLED();
    drawMeteo();
}
