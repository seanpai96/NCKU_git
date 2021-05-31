package seanpai.java;

public class Store {
    public static void main(String[] args) {
        Payment p1 = new Payment();
        p1.checkout();
        CreditCardPayment p2 = new CreditCardPayment();
        Object a = (Object) p2;
        Payment p = (Payment) a;
        p2.checkout();
    }
}
