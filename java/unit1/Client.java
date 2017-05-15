import java.io.*;
import java.net.*;

// Simple Client class to connect to server
// and send a msg.
class Client {
    public static void main(String args[]) throws IOException {

        String msg;

        // socket to establish connection
        Socket s = new Socket("localhost", 7070);

        // create a raw pip to read data from server
        InputStream instream = s.getInputStream();

        // create a buffer to store read data in bulk
        BufferedReader br = new BufferedReader(new InputStreamReader(instream));

        while ((msg = br.readLine()) != null)
            System.out.println("From Server: " + msg);

        // close connections
        br.close();
        s.close();
    }
}
