package seanpai.java;

public class CallByReference {
    public static void main(String[] args) {
        ToyClass toy = new ToyClass("sean", 10);
        System.out.println(toy);

        changer(toy);
        System.out.println(toy);
    }

    public static void changer(ToyClass param){
        param.set("SEANPAI", 69);
    }

}
