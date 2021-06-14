package sample;

import javafx.fxml.Initializable;

import java.io.*;
import java.net.*;
import java.util.ResourceBundle;

public class Server {

    public Server(){
        try{
            var serverSocket = new ServerSocket(0);
            var connectionSock = serverSocket.accept();
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(connectionSock.getInputStream()));
            DataOutputStream clientOutput = new DataOutputStream(connectionSock.getOutputStream());

            String clientText = clientInput.readLine();
            System.out.println("Received" + clientText);


        } catch (IOException e) {
            e.printStackTrace();
        }
    }



}
