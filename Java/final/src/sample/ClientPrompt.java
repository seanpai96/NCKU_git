package sample;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ClientPrompt implements Initializable {
    @FXML
    Button joinButton, cancelButton;
    @FXML
    TextField ipField, portField;

    MultiPlayer multiPlayer;
    Server serv;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        multiPlayer = new MultiPlayer();
        serv = multiPlayer.server;
        serv.start();
        joinButton.setOnMouseClicked(event -> {
            if (Integer.parseInt(portField.getText()) == 0){
                portField.setText("");
                return;
            }
            String result = multiPlayer.client.connect(ipField.getText(), Integer.parseInt(portField.getText()), "client");

            if (result.equals("Success")){
                Parent root;
                try {
                    FXMLLoader fxmlLoader = new FXMLLoader();
                    fxmlLoader.setController(multiPlayer);
                    fxmlLoader.setLocation(getClass().getResource("MultiPlayer.fxml"));
                    root = fxmlLoader.load();
                    Stage stage = (Stage)((Node)event.getSource()).getScene().getWindow();
                    Scene scene = new Scene(root);
                    stage.setResizable(false);
                    stage.setScene(scene);
                    stage.show();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        cancelButton.setOnMouseClicked(this::cancel);
    }

    private void cancel(MouseEvent event){
        Client cli = multiPlayer.client;
        cli.stopSelf(Integer.parseInt(multiPlayer.server.getPort()));
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
}
