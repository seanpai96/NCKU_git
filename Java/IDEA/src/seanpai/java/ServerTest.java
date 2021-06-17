package seanpai.java;

import java.io.IOException;
import java.net.Inet4Address;
import java.net.ServerSocket;
import java.util.Arrays;

public class ServerTest {
    public static void main(String[] args) throws IOException {
        var serverSocket = new ServerSocket(0);
        System.out.println(serverSocket.getLocalPort());
    }
}
