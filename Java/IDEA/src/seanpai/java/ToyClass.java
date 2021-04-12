package seanpai.java;

public class ToyClass {
    private String name;
    private int number;

    public ToyClass(String name, int number){
        this.name = name;
        this.number = number;
    }


    public String toString(){
        return (name + " " + number);

    }

    public void set(String newName, int newNumber){
        name = newName;
        number = newNumber;
    }


}
