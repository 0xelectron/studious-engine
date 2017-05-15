import java.io.*;
import java.net.*;
import java.util.Date;

// Simple Server class to respond to client
// and send a msg.
class Server {
    public static void main(String args[]) throws IOException {

        Date d = new Date();

        // socket to establish connection
        ServerSocket ss = new ServerSocket(7070);

        // sleep till any request arrives
        Socket s = ss.accept();

        // create raw pipe to send msg to client
        OutputStream outstream = s.getOutputStream();

        // create string pip to send msg to client
        PrintStream ps = new PrintStream(outstream);

        // Send msg to client
        ps.printf("[%s] Hey!", d.toString());

        // close connections
        ps.close();
        s.close();
        ss.close();
    }
}
