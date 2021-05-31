package sample;

import javafx.event.ActionEvent;
import javafx.scene.control.Label;


public class Controller {
    public Label hiText;
    boolean i = true;
    public void buttonClicked(ActionEvent actionEvent) {
        hiText.setText(i ? "Hello, world!" : "");
        i = !i;
    }
}
