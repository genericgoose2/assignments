package JavaClient;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class SimpleClient {
    public static void main(String[] args) {
        String serverName = "127.0.0.1";
        int port = 1111;

        try {
            System.out.println("Connecting to " + serverName + " on port " + port);
            Socket client = new Socket(serverName, port);
            System.out.println("Just connected to " + client.getRemoteSocketAddress());

            OutputStream outToServer = client.getOutputStream();
            DataOutputStream out = new DataOutputStream(outToServer);

            InputStream inFromServer = client.getInputStream();
            DataInputStream in = new DataInputStream(inFromServer);

            // Start a new thread to continuously read messages from the server
            new Thread(() -> {
                try {
                    System.out.println("Listen the server");
                    while (true) {
                        System.out.println("Server says " + in.readByte());
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }).start();


            // Get user input
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("Enter a message to send to the server:");
                String message = scanner.nextLine();
                System.out.println(message);
                if(message.equals("quit"))
                {
                    out.writeChars("0"+ '\0');
                    out.flush();
                    out.close();
                    in.close();
                    client.close();
                    System.exit(0);
                    break;
                }

                if (message.length() > 100) {
                    System.out.println("Message is too long. Please enter a message of 100 characters or less.");
                    continue;
                }
                out.writeBytes(message + '\n');
                out.flush();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
