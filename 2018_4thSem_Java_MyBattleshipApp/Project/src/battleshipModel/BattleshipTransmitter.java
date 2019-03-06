package battleshipModel;

import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;



/**
 * klasa obsługująca wysyłanie wiadomości
 */
public class BattleshipTransmitter extends Thread { //klasa do wysylania wiadomosci

    String message, hostname;
    int port;
    
    public String getHostname() {
    	return hostname;
    }
    
    public int getTransmitPort () {
    	return port;
    }
    
    public BattleshipTransmitter() {
    }

    /**
	 * główny konstruktor klasy
	 */
    public BattleshipTransmitter(String message, String hostname, int port) {
        this.message = message;
        this.hostname = hostname;
        this.port = port;
    }

    @Override
    /**
	 * metoda wysyłająca wiadomość
	 */
    public void run() {
        try {
            Socket s = new Socket(hostname, port);
            s.getOutputStream().write(message.getBytes()); 
            //System.out.println("Transmitter sent message: " + message);
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(BattleshipTransmitter.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

/*public class BattleshipTransmitter extends Thread {
	String message,hostname;
    int port;
    
    public BattleshipTransmitter() {
    }

    public BattleshipTransmitter(String message, String hostname, int port) {
        this.message = message;
        this.hostname = hostname;
        this.port = port;
    }

    @Override
    public void run() {
        try {
            Socket s = new Socket(hostname, port);
            s.getOutputStream().write(message.getBytes());
            System.out.println("mama");
            s.close();
        } catch (IOException e) {
            //System.out.println("Problems with transmitting messages: " + e);
        }
    }
		
}*/
