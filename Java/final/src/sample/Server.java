package sample;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Inet4Address;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class Server extends Thread {
    MultiPlayer main;
    ServerSocket serverSocket;
    Socket connectionSock;
    boolean ongoingConnection = false;

    public Server(MultiPlayer mul) {
        main = mul;

    }

    public String getPort() {
        return String.valueOf(serverSocket.getLocalPort());
    }

    public String getIP() {
        try {
            return Inet4Address.getLocalHost().getHostAddress();
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
        return "error";
    }



    @Override
    public void run() {
        try {
            serverSocket = new ServerSocket(0);
            connectionSock = serverSocket.accept();
            ongoingConnection = true;
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(connectionSock.getInputStream()));
            while (true) {
                String clientText = clientInput.readLine();
                System.out.println("Received" + clientText);
                if (clientText.equals("seeya")) {
                    ongoingConnection = false;
                    break;
                }
                main.incomingMessage(clientText);
            }
            connectionSock.close();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


