import processing.serial.*;

Serial myPort;
boolean isSerialOn=false;

void setup() 
{
    size(600, 400, P2D);
    initLED();
	initMeteo();	

    if (isSerialOn && Serial.list().length>0) {
        String portName = Serial.list()[1];
        myPort = new Serial(this, portName, 115200);
    }
    initLED();
}

void draw() {
    background(0);
    runLED();
    drawMeteo();
}

void serialEvent(Serial p) { 
    println(p.readBytes());
} 
