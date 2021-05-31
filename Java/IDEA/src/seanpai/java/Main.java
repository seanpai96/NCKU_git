package seanpai.java;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        File file = new File("test.txt");
        try {
            Scanner sc = new Scanner(file);
            System.out.println(sc.nextLine());
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }


    }
}
