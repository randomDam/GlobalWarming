//---------------------------------------------------------
// LED SYSTEM
//---------------------------------------------------------
PGraphics zone;
//---------------------------------------------------------
//INIT LED SYSTEM
//---------------------------------------------------------
void initLED() {
    zone = createGraphics(8, 8, P2D);
    ((PGraphicsOpenGL)zone).textureSampling(2);
}
//---------------------------------------------------------
//RUN LED
//---------------------------------------------------------
void runLED() {
    zone.beginDraw();
    //zone.image(ims[indexI], 0, 0);
    zone.endDraw();
    zone.loadPixels();

    image(zone, 20, 20, 8*8, 8*8);

    if (frameCount>10 && frameCount%5==0) {
        sendZone();
    }
}
//---------------------------------------------------------
//SEND RANDOM
//---------------------------------------------------------
void sendRandom() {
    byte [] data = new byte[64*3+1];
    data[0] = byte(0x01);

    for (int i=1; i<data.length; i+=3) {
        data[i]=byte(random(200));
        data[i+1]=byte(random(200));
        data[i+2]=byte(random(200));
    }
    myPort.write(data);
}
//---------------------------------------------------------
//SEND TEST RED
//---------------------------------------------------------
int index=0;
void sendTest_UNI(int r, int g, int b) {
    byte [] data = new byte[64*3+1];
    data[0] = byte(0x01);

    for (int i=1; i<data.length; i+=3) {
        data[i]=byte(0);
        data[i+1]=byte(0);
        data[i+2]=byte(0);
    }

    data[1+index]=byte(r);
    data[1+index+1]=byte(g);
    data[1+index+2]=byte(b);

    myPort.write(data);
    index+=3;
    if (index>=64*3)index=0;
}
//---------------------------------------------------------
//SEND ZONE
//---------------------------------------------------------
void sendZone() {
    byte [] data = new byte[64*3+1];
    data[0] = byte(0x01);

    for (int i=0; i<zone.pixels.length; i++) {
        data[i*3+1]=(byte)red(zone.pixels[i]);
        data[i*3+2]=(byte)green(zone.pixels[i]);
        data[i*3+3]=(byte)blue(zone.pixels[i]);
    }
    
    if(isSerialOn)myPort.write(data);
}
