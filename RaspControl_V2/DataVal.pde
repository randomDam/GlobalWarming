class DataVal {
    float val;
    float val_min;
    float val_max;

    String name;
    boolean isInit=false;

    DataVal(String name) {
        this.name=name;
    }

    void set(float v) {
        if (isInit==false) {
            this.val=v;
            this.val_min=v;
            this.val_max=v;
            isInit=true;
        } else {
            if (v<val_min) {
                val_min=v;
            }
            if (v>val_max) {
                val_max=v;
            }
        }
    }
}
