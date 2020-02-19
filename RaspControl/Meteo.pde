PImage [] ims = new PImage[4];
PFont typo;
//VAR
int temparature=0;
int pression=0;
int altitude=0;
int humidity=0;

//
void initMeteo() {
    ims[0] = loadImage("pink.png");
    ims[1] = loadImage("soleil.png");
    ims[2] = loadImage("raz.png");
    ims[3] = loadImage("invader.png");

    typo = loadFont("InputMono-Regular-15.vlw");
}

void drawMeteo() {
    fill(255);
    textFont(typo);
    
    text("Meteo Dispatcher", 10, 20);

    int px=10;
    int py=60;
    int margeY=20;

    text("Temp : "+temparature, px, py);
    py+=margeY;
    text("Press : "+pression, px, py);
    py+=margeY;
    text("Alti : "+altitude, px, py);
    py+=margeY;
    text("Humi : "+altitude, px, py);
    py+=margeY;
}
