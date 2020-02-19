
String inString="";

void serialEvent(Serial p) { 
    println(p.readBytes());
    inString = p.readString();

    String [] datas = split(inString, "|");

    if (datas.length>=dataVals.length) {
        for (int i=0; i<dataVals.length; i++) {
            dataVals[i].val = float(datas[i]);
        }
    }
}
