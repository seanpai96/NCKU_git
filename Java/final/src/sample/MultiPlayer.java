package sample;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.util.Duration;
import javafx.util.Pair;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.ResourceBundle;

public class MultiPlayer implements Initializable {
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
    Label scoreLabel, timeLabel, turnLabel;

    Server server = new Server(this);
    Client client = new Client(this);
    ServerPrompt serverPrompt;

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
    boolean myTurn = false;

    Image cover = new Image(getClass().getResourceAsStream("cards/default.png"));

    String[] cardIdArray = {"A", "A", "B", "B", "C", "C", "D", "D", "E", "E", "F", "F", "G", "G", "H", "H", "I", "I", "J", "J"};
    ArrayList<String> cardID = new ArrayList<>(Arrays.asList(cardIdArray));

    Pair<Pair<Integer, Integer>, ImageView> pair1, pair2 = new Pair<>(new Pair<>(-1,-1),null);
    int score = 0;
    int myScore = 0;
    long time = 0;

    MultiPlayer(ServerPrompt serverPrompt){
        this.serverPrompt = serverPrompt;
        Collections.shuffle(cardID);
    }

    MultiPlayer(){
        Collections.shuffle(cardID);
    }

    Timeline tl;
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        reset();
        imageA1.setOnMouseClicked(event -> flipCard(0,0, imageA1, false));
        imageB1.setOnMouseClicked(event -> flipCard(0,1, imageB1, false));
        imageC1.setOnMouseClicked(event -> flipCard(0,2, imageC1, false));
        imageD1.setOnMouseClicked(event -> flipCard(0,3, imageD1, false));
        imageA2.setOnMouseClicked(event -> flipCard(1,0, imageA2, false));
        imageB2.setOnMouseClicked(event -> flipCard(1,1, imageB2, false));
        imageC2.setOnMouseClicked(event -> flipCard(1,2, imageC2, false));
        imageD2.setOnMouseClicked(event -> flipCard(1,3, imageD2, false));
        imageA3.setOnMouseClicked(event -> flipCard(2,0, imageA3, false));
        imageB3.setOnMouseClicked(event -> flipCard(2,1, imageB3, false));
        imageC3.setOnMouseClicked(event -> flipCard(2,2, imageC3, false));
        imageD3.setOnMouseClicked(event -> flipCard(2,3, imageD3, false));
        imageA4.setOnMouseClicked(event -> flipCard(3,0, imageA4, false));
        imageB4.setOnMouseClicked(event -> flipCard(3,1, imageB4, false));
        imageC4.setOnMouseClicked(event -> flipCard(3,2, imageC4, false));
        imageD4.setOnMouseClicked(event -> flipCard(3,3, imageD4, false));
        imageA5.setOnMouseClicked(event -> flipCard(4,0, imageA5, false));
        imageB5.setOnMouseClicked(event -> flipCard(4,1, imageB5, false));
        imageC5.setOnMouseClicked(event -> flipCard(4,2, imageC5, false));
        imageD5.setOnMouseClicked(event -> flipCard(4,3, imageD5, false));
        if(myTurn){
            turnLabel.setText("Your Turn");
        }else{
            turnLabel.setText("Other's Turn");
        }
    }



    private void flipCard(int col, int row, ImageView imageView, boolean isNetwork) {
        if (!flippable || (!myTurn&&!isNetwork)){
            return;
        }
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
        if(!flippedCard[col][row]){
            Image cardImage = new Image(getClass().getResourceAsStream("cards/" + cardID.get(row+col*4) + ".png"));
            imageView.setImage(cardImage);
            if(!isNetwork){
                sendFlipCard(col, row, true);
            }
            if(isFlipped){
                flippable = false;
                pair2 = new Pair<>(new Pair<>(col, row), imageView);
                var det1 = cardID.get(pair1.getKey().getValue()+pair1.getKey().getKey()*4);
                var det2 = cardID.get(pair2.getKey().getValue()+pair2.getKey().getKey()*4);
                if(det1.equals(det2)){
                    flippedCard[pair2.getKey().getKey()][pair2.getKey().getValue()] = true;
                    score++;
                    if(!isNetwork) myScore++;
                    scoreLabel.setText("Score: " + myScore);
                    if(score == 10){
                        tl.stop();
                    }
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
                myTurn = !myTurn;
                Platform.runLater(() -> {
                    if(myTurn){
                        turnLabel.setText("Your Turn");
                    }else{
                        turnLabel.setText("Other's Turn");
                    }
                    if(score == 10){
                        if(myScore > 5){
                            turnLabel.setText("You Win!");
                        }else if (myScore == 5){
                            turnLabel.setText("Tie!");
                        }else{
                            turnLabel.setText("You Lose!");
                        }
                    }
                });

                isFlipped = false;
            }else{
                flippable = false;
                isFlipped = true;
                if(!isNetwork){
                    sendFlipCard(col, row, false);
                }
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
        score = 0;
        myScore = 0;
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

    private void sendJSONtoCpnt(){
        JSONArray a = new JSONArray();
        for(String s: cardID){
            a.put(s);
        }
        String msg = String.format("{\"request\": \"set_array\",\"array\": %s}", a);
        client.sendMessage(msg);
    }

    private void sendFlipCard(int col, int row, boolean change){
        String msg = String.format("{\"request\": \"flip\",\"col\": %d, \"row\": %d, \"change\": %b}", col, row, change);
        client.sendMessage(msg);
    }

    public void incomingMessage(String message){
        if(message.equals("seeya")) return;
        JSONObject input = new JSONObject(message);
        String request;
        try{
            request = input.getString("request");
        }catch (JSONException e){
            e.printStackTrace();
            return;
        }
        switch (request){
            case "connect":
                if(input.getString("type").equals("client")){
                    String result = client.connect(input.getString("ip"), input.getInt("port"), "server");if(serverPrompt != null && result.equals("Success")){
                        Platform.runLater(() -> {
                            sendJSONtoCpnt();
                            serverPrompt.nextScene();
                        });
                    }
                    myTurn = true;
                }

                break;
            case "set_array":
                JSONArray array = input.getJSONArray("array");
                cardID.clear();
                array.forEach(e ->{
                    var s = (String) e;
                    cardID.add(s);
                });
                break;
            case "flip":
                int col = input.getInt("col"), row = input.getInt("row");
                boolean change = input.getBoolean("change");
                flipCard(col, row, getViewByNum(col, row), true);
                if(change){
                    flippable = true;
                }
                break;
            default:
                break;
        }
    }

    private ImageView getViewByNum(int col, int row){
        if(col == 0 && row == 0){
            return imageA1;
        }else if(col == 0 && row == 1){
            return imageB1;
        }else if(col == 0 && row == 2){
            return imageC1;
        }else if(col == 0 && row == 3){
            return imageD1;
        }else if(col == 1 && row == 0){
            return imageA2;
        }else if(col == 1 && row == 1){
            return imageB2;
        }else if(col == 1 && row == 2){
            return imageC2;
        }else if(col == 1 && row == 3){
            return imageD2;
        }else if(col == 2 && row == 0){
            return imageA3;
        }else if(col == 2 && row == 1){
            return imageB3;
        }else if(col == 2 && row == 2){
            return imageC3;
        }else if(col == 2 && row == 3){
            return imageD3;
        }else if(col == 3 && row == 0){
            return imageA4;
        }else if(col == 3 && row == 1){
            return imageB4;
        }else if(col == 3 && row == 2){
            return imageC4;
        }else if(col == 3 && row == 3){
            return imageD4;
        }else if(col == 4 && row == 0){
            return imageA5;
        }else if(col == 4 && row == 1){
            return imageB5;
        }else if(col == 4 && row == 2){
            return imageC5;
        }else if(col == 4 && row == 3){
            return imageD5;
        }else{
            return null;
        }
    }
}
