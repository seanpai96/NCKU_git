package sample;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    @FXML
    Button singlePlayer, multiPlayerCreate, multiPlayerJoin;
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        singlePlayer.setOnMouseClicked( event -> teleport("SinglePlayer", event));
        multiPlayerCreate.setOnMouseClicked( event ->teleport("serverPrompt", event));
        multiPlayerJoin.setOnMouseClicked(event ->teleport("clientPrompt", event));
    }
    void teleport(String name, MouseEvent event){
        Parent root;
        try {
            root = FXMLLoader.load(getClass().getResource(name + ".fxml"));
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
