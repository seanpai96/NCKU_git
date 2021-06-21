package sample;

import java.io.*;
import java.net.*;

public class Client extends Thread{
    MultiPlayer multiPlayer;
    Socket cSock;
    DataOutputStream serverOutput;

    Client(MultiPlayer mp){
        multiPlayer = mp;
    }

    public String connect(String ip, int port, String type){
        try {
            cSock = new Socket(ip, port);
            serverOutput = new DataOutputStream(cSock.getOutputStream());
            String m = String.format("{\"request\": \"connect\",\"ip\": \"%s\",\"port\": %s, \"type\": \"%s\"}", multiPlayer.server.getIP(), multiPlayer.server.getPort(), type);
            sendMessage(m);
            return "Success";
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "Error";
    }

    public void sendMessage(String message){
        if(!message.equals("")){
            try {
                serverOutput.writeBytes(message + '\n');
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void stopClient(){
        try {
            sendMessage("seeya");
            cSock.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void stopSelf(int port){
        try {
            cSock = new Socket("localhost", port);
            serverOutput = new DataOutputStream(cSock.getOutputStream());
            sendMessage("seeya");
            cSock.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
