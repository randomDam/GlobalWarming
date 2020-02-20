PImage [] ims = new PImage[9];
PFont typo;
//VAR
String [] names = {
    "temparature", 
    "pression", 
    "altitude", 
    "humidity", 
    "winddir", 
    "windspeedmph", 
    "windgustmph", 
    "windgustdir", 
    "windspdmph_avg2m", 
    "winddir_avg2m", 
    "windgustmph_10m", 
    "windgustdir_10m", 
    "rainin", 
    "dailyrainin", 
    "batt_lvl", 
    "light_lvl", 
};
DataVal [] dataVals = new DataVal[names.length];

//
void initMeteo() {
    ims[0] = loadImage("faibleLum.png");
    ims[1] = loadImage("forteLum.png");
    ims[2] = loadImage("obscurite.png");
    ims[3] = loadImage("pollution2.png");
    ims[4] = loadImage("poolution.png");
    ims[5] = loadImage("raz.png");
    ims[6] = loadImage("temp10-20C.png");
    ims[7] = loadImage("temp20-30C.png");//temp0-10C
	ims[8] = loadImage("temp0-10C.png");//

    typo = loadFont("InputMono-Regular-15.vlw");

    for (int i=0; i<dataVals.length; i++) {
        dataVals[i] = new DataVal(names[i]);
    }
}

void drawMeteo() {
    fill(255);
    textFont(typo);

    text("Meteo Dispatcher", 10, 20);

    int px=10;
    int py=60;
    int margeY=20;

    for (int i=0; i<dataVals.length; i++) {
        fill(255);
        text(dataVals[i].name+" > ", px, py+margeY*i);
        
        fill(150);
        text(dataVals[i].val_min, px+200, py+margeY*i);
        
        fill(255);
        text(dataVals[i].val, px+300, py+margeY*i);
        
        fill(150);
        text(dataVals[i].val_max, px+400, py+margeY*i);
    }
}
