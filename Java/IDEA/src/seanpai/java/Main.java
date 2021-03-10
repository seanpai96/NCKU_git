package seanpai.java;


import java.util.Random;

public class Main {

    public static void main(String[] args) {
        Random rand = new Random();
        for(int i=0;i<100;i++){
            int x = rand.nextInt(40);
            System.out.println(x);
        }
    }
}
