package sample;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.concurrent.Task;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.util.Duration;
import javafx.util.Pair;

import java.net.URL;
import java.util.*;

public class SinglePlayer implements Initializable {
    @FXML
    ImageView imageA1, imageB1, imageC1, imageD1;
    @FXML
    ImageView imageA2, imageB2, imageC2, imageD2;
    @FXML
    ImageView imageA3, imageB3, imageC3, imageD3;
    @FXML
    ImageView imageA4, imageB4, imageC4, imageD4;
    @FXML
    ImageView imageA5, imageB5, imageC5, imageD5;
    @FXML
    Label scoreLabel, timeLabel;
    @FXML
    Button resetButton;

    boolean[][] flippedCard = {
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
    };
    boolean isFlipped = false;
    boolean flippable = true;
    boolean firstCard = true;

    Image cover = new Image(getClass().getResourceAsStream("cards/default.png"));

    String[] cardIdArray = {"A", "A", "B", "B", "C", "C", "D", "D", "E", "E", "F", "F", "G", "G", "H", "H", "I", "I", "J", "J"};
    ArrayList<String> cardID = new ArrayList<>(Arrays.asList(cardIdArray));

    Pair<Pair<Integer, Integer>, ImageView> pair1, pair2 = new Pair<>(new Pair<>(-1,-1),null);
    int score = 0;
    long time = 0;

    Timeline tl;
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        reset();
        imageA1.setOnMouseClicked(event -> flipCard(0,0, imageA1));
        imageB1.setOnMouseClicked(event -> flipCard(0,1, imageB1));
        imageC1.setOnMouseClicked(event -> flipCard(0,2, imageC1));
        imageD1.setOnMouseClicked(event -> flipCard(0,3, imageD1));
        imageA2.setOnMouseClicked(event -> flipCard(1,0, imageA2));
        imageB2.setOnMouseClicked(event -> flipCard(1,1, imageB2));
        imageC2.setOnMouseClicked(event -> flipCard(1,2, imageC2));
        imageD2.setOnMouseClicked(event -> flipCard(1,3, imageD2));
        imageA3.setOnMouseClicked(event -> flipCard(2,0, imageA3));
        imageB3.setOnMouseClicked(event -> flipCard(2,1, imageB3));
        imageC3.setOnMouseClicked(event -> flipCard(2,2, imageC3));
        imageD3.setOnMouseClicked(event -> flipCard(2,3, imageD3));
        imageA4.setOnMouseClicked(event -> flipCard(3,0, imageA4));
        imageB4.setOnMouseClicked(event -> flipCard(3,1, imageB4));
        imageC4.setOnMouseClicked(event -> flipCard(3,2, imageC4));
        imageD4.setOnMouseClicked(event -> flipCard(3,3, imageD4));
        imageA5.setOnMouseClicked(event -> flipCard(4,0, imageA5));
        imageB5.setOnMouseClicked(event -> flipCard(4,1, imageB5));
        imageC5.setOnMouseClicked(event -> flipCard(4,2, imageC5));
        imageD5.setOnMouseClicked(event -> flipCard(4,3, imageD5));
        resetButton.setOnMouseClicked(event -> reset());
    }


    private void flipCard(int col, int row, ImageView imageView) {
        if (firstCard){
            time = 0;
            tl = new Timeline(new KeyFrame(Duration.millis(100), ev->{
                time++;
                timeLabel.setText("Time: " + (double)time/10 + "s");
            }));
            tl.setCycleCount(Animation.INDEFINITE);
            tl.play();
            firstCard = false;
        }
        if (!flippable){
            return;
        }
        if(!flippedCard[col][row]){
            Image cardImage = new Image(getClass().getResourceAsStream("cards/" + cardID.get(row+col*4) + ".png"));
            imageView.setImage(cardImage);
            if(isFlipped){
                flippable = false;
                pair2 = new Pair<>(new Pair<>(col, row), imageView);
                var det1 = cardID.get(pair1.getKey().getValue()+pair1.getKey().getKey()*4);
                var det2 = cardID.get(pair2.getKey().getValue()+pair2.getKey().getKey()*4);
                if(det1.equals(det2)){
                    flippedCard[pair2.getKey().getKey()][pair2.getKey().getValue()] = true;
                    score++;
                    scoreLabel.setText("Score: " + score);
                    if(score == 10){
                        scoreLabel.setText("Complete!");
                        tl.stop();
                    }
                    flippable = true;
                }else{
                    Task<Void> sleeper = new Task<>() {
                        @Override
                        protected Void call() {
                            try {
                                Thread.sleep(1000);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                            return null;
                        }
                    };
                    sleeper.setOnSucceeded(event -> {
                        reverse(pair1.getKey().getKey(), pair1.getKey().getValue(), pair1.getValue());
                        reverse(pair2.getKey().getKey(), pair2.getKey().getValue(), pair2.getValue());
                        flippable = true;
                    });
                    new Thread(sleeper).start();
                }
                isFlipped = false;
            }else{
                flippable = false;
                isFlipped = true;
                pair1 = new Pair<>(new Pair<>(col, row), imageView);
                flippedCard[pair1.getKey().getKey()][pair1.getKey().getValue()] = true;
                flippable = true;
            }
        }
    }

    private void reverse(int col, int row, ImageView imageView){
        imageView.setImage(cover);
        flippedCard[col][row] = false;
    }

    private void reset() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                flippedCard[i][j] = false;
            }
        }
        isFlipped = false;
        firstCard = true;
        Collections.shuffle(cardID);
        score = 0;
        scoreLabel.setText("Score: 0");
        time = 0;
        timeLabel.setText("Time: 0.0s");
        if(tl != null){
            tl.stop();
        }
        imageA1.setImage(cover);
        imageB1.setImage(cover);
        imageC1.setImage(cover);
        imageD1.setImage(cover);
        imageA2.setImage(cover);
        imageB2.setImage(cover);
        imageC2.setImage(cover);
        imageD2.setImage(cover);
        imageA3.setImage(cover);
        imageB3.setImage(cover);
        imageC3.setImage(cover);
        imageD3.setImage(cover);
        imageA4.setImage(cover);
        imageB4.setImage(cover);
        imageC4.setImage(cover);
        imageD4.setImage(cover);
        imageA5.setImage(cover);
        imageB5.setImage(cover);
        imageC5.setImage(cover);
        imageD5.setImage(cover);

    }


}
