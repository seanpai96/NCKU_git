package seanpai.java;

public class callByValue {
    int age = 1;

    public static void main(String[] args) {
        callByValue value1 = new callByValue();
        callByValue value2 = value1;
        value2.age = 2;
        System.out.println(value1.age);
    }
}
