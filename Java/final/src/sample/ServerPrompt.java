package sample;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;


public class ServerPrompt implements Initializable {
    @FXML
    Label infoLabel;
    @FXML
    Button cancelButton;

    Server serv;
    MultiPlayer multiPlayer;
    String port;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        multiPlayer = new MultiPlayer(this);
        serv = multiPlayer.server;
        serv.start();
        String ip = serv.getIP();
        port = serv.getPort();
        String info = "請以\n" + ip + ":" + port + "\n加入";
        infoLabel.setText(info);
        cancelButton.setOnMouseClicked(this::cancel);
    }

    public void cancel(MouseEvent event){
        Client cli = multiPlayer.client;
        cli.stopSelf(Integer.parseInt(port));
        Parent root;
        try {
            root = FXMLLoader.load(getClass().getResource( "sample.fxml"));
            Stage stage = (Stage)((Node)event.getSource()).getScene().getWindow();
            Scene scene = new Scene(root);
            stage.setResizable(false);
            stage.setScene(scene);
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void nextScene(){
        Parent root;
        try {
            FXMLLoader fxmlLoader = new FXMLLoader();
            fxmlLoader.setController(multiPlayer);
            fxmlLoader.setLocation(getClass().getResource("MultiPlayer.fxml"));
            root = fxmlLoader.load();
            Stage stage = (Stage)infoLabel.getScene().getWindow();
            Scene scene = new Scene(root);
            stage.setResizable(false);
            stage.setScene(scene);
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
