package seanpai.java;

public class Main {

    public static void main(String[] args) {
        Student sean = new Student();
        sean.height = 175;
        sean.weight = 75;
        sean.chinese.score = 50;

	    System.out.println("Sean's Chinese score is " + sean.chinese.score + "!\n");
	    if(sean.isFail()){
            System.out.println("Sean failed Chinese!");
        }
    }


    public static class Student{
        int height;
        int weight;
        Subject chinese = new Subject();

        public void setChinese(Subject chinese) {
            this.chinese = chinese;
        }

        private boolean isFail(){
            if(chinese.score < 60){
                return true;
            }else{
                return false;
            }
        }

    }

    public static class Subject{
        int score;
    }
}
