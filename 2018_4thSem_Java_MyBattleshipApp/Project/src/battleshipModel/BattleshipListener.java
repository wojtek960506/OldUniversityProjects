package battleshipModel;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;




/**
 * klasa obsługująca nasłuchiwanie na przychodzące wiadomości
 *  
 */
public class BattleshipListener extends Thread {
    
    ServerSocket server;
    int port;
    int firstPlayer;
    String line;
    boolean yourTurn;
    BoxTypeFromMessage boxTypeFromMessage;
    
    /**
     * zmienna określająca czy przyszła wiadomość zwrotna
     */
    private boolean ifMessageBack;
    
    /**
     * zmienna określająca czy gra została zakończona
     */
    private boolean result;
    
    /**
     * zmienna określająca czy zostały już ustawione wszystkie statki
     */
    private boolean notSetYet;
    
    public BoxType board[][];
    
    public Ship[] shipsArray;
    
    public int boardWithPlacedShips[][];
    
    int i; //variables for sending position
    int j;
    
    /**
	 * getter dla zmiennej notSsetYet
	 *
	 */
    public boolean ifNotSetYet() {
		return notSetYet;
	}

    /**
	 * setter dla zmiennej notSsetYet
	 *
	 */
	public void setNotSetYet(boolean notSetYet) {
		this.notSetYet = notSetYet;
	}

	/**
	 * getter dla zmiennej result
	 *
	 */
	public boolean getResult() {
		return result;
	}

	/**
	 * setter dla zmiennej result
	 *
	 */
	public void setResult(boolean result) {
		this.result = result;
	}

	/**
	 * getter dla zmiennej ifMessageback
	 *  
	 */
	public boolean getIfMessageBack() {
		return ifMessageBack;
	}
	
	/**
	 * setter dla zmiennej ifMessageback
	 *
	 */
	public void setIfMessageBack(boolean ifMessageBack) {
		this.ifMessageBack = ifMessageBack;
	}

	/**
	 * getter dla zmiennej boxTypeFromMessage
	 *
	 */
	public BoxTypeFromMessage getBoxTypeFromMessage() {
    	return boxTypeFromMessage;
    }
    
	/**
	 * setter dla zmiennej boxTypeFromMessage
	 *
	 */
    public void setBoxTypeFromMessage(BoxTypeFromMessage b) {
    	boxTypeFromMessage = b;    	
    }
    
    /**
	 * getter dla zmiennej yourTurn
	 *
	 */
    public boolean isYourTurn() {
    	return yourTurn;
    }
    
    /**
	 * setter dla zmiennej yourTurn
	 *
	 */
    public void changeTurn(boolean b) {
    	yourTurn = b;
    }
    
    /**
	 * getter dla zmiennej i
	 *
	 */
    public int getI() {
    	return i;
    }
    
    /**
	 * getter dla zmiennej j
	 *
	 */
    public int getJ() {
    	return j;
    }
    
    /**
	 * konstruktor na podstawie numeru portu na którym generujemy słuchacza
 	 *
	 */
    public BattleshipListener(int port){
        this.port = port;
        boxTypeFromMessage = BoxTypeFromMessage.INITIALIZE_MESSAGE;
        ifMessageBack = false;
        yourTurn = true;
        result = false;
        setNotSetYet(true);
        shipsArray = new Ship[BattleshipModel.SHIPS_NUMBER];
        board = new BoxType[BattleshipModel.BOARD_SIZE][BattleshipModel.BOARD_SIZE];
        boardWithPlacedShips = new int[BattleshipModel.BOARD_SIZE][BattleshipModel.BOARD_SIZE];
        for(int i1 = 0 ; i1 < BattleshipModel.BOARD_SIZE ; i1++) {
			for(int j1 = 0 ; j1 < BattleshipModel.BOARD_SIZE ; j1++) {
				board[i1][j1] = BoxType.EMPTY;
			}
        }
        
        for(int i1 = 0 ; i1 < BattleshipModel.BOARD_SIZE ; i1++) {
			for(int j1 = 0 ; j1 < BattleshipModel.BOARD_SIZE ; j1++) {
				boardWithPlacedShips[i1][j1] = -1;
			}
        }
        
        for(int i1 = 0 ; i1 < BattleshipModel.SHIPS_NUMBER ; i1++) {
			shipsArray[i1] = new Ship();
		}
        
        firstPlayer = 2;
        
        
        try {
            server = new ServerSocket(port);
        } catch (IOException ex) {
            Logger.getLogger(BattleshipListener.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    

    @Override
    /**
	 * metoda uruchamiająca nasluchiwanie na danym porcie
	 * 
	 */
    public void run() {
        Socket clientSocket = null;
        try {
        	clientSocket = server.accept();
            while((clientSocket = server.accept()) != null){
                InputStream is = clientSocket.getInputStream();
                BufferedReader br = new BufferedReader(new InputStreamReader(is)); 
                line = br.readLine();
                if(line != null){ 
                	
                	if(line.equals("You win")) {
                		setResult(true);
                	}
                	
                	if(line.length() == 10) {
                		int i1 = (int)(line.charAt(0))-48;
            			int j1 = (int)(line.charAt(4))-48;
            			int v1 = (int)(line.charAt(8))-48; //value 
            			
            			if	(v1 == 30) {
            				boardWithPlacedShips[i1][j1] = -1;
            			}
            			else {
            				boardWithPlacedShips[i1][j1] = v1;
            			}
                	}
                	
                	
                	if(line.length() == 15) {
                		int l = (int)(line.charAt(0))-48;
                		int fM = (int)(line.charAt(2))-48;
                		int fN = (int)(line.charAt(4))-48;
                		int lM = (int)(line.charAt(6))-48;
                		int lN = (int)(line.charAt(8))-48;
                		int h = (int)(line.charAt(10))-48;
                		int d = (int)(line.charAt(12))-48;
                		int i1 = (int)(line.charAt(14))-48;
                		
                		shipsArray[i1].length = l;
                		shipsArray[i1].firstM = fM;     	
                		shipsArray[i1].firstN = fN;
                		shipsArray[i1].lastM = lM;
                		shipsArray[i1].lastN = lN;
                		shipsArray[i1].health = h;
                		if(d == 1) {
                			shipsArray[i1].direction = ShipDirection.VERTICAL;
                		}
                		else {
                			shipsArray[i1].direction = ShipDirection.HORIZONTAL; //horizontal
            			}
                		
                	}
                	
                	if(line.length() == 9) {
                		
                		int i1 = (int)(line.charAt(0))-48;
                		int j1 = (int)(line.charAt(4))-48;
                		int v1 = (int)(line.charAt(8))-48; //value 
                		
                		switch(v1) {
                			case 0: //empty
                				board[i1][j1] = BoxType.EMPTY;
                				break;
                			case 1: //positioned
                				board[i1][j1] = BoxType.POSITIONED;
                				break;
                			case 2: //hit
                				board[i1][j1] = BoxType.HIT;
                				break;
                			case 3: //miss
                				board[i1][j1] = BoxType.MISS;
                				break;
                			default:
                				break;
                		}
                		
                	}
                	
                	if(line.equals("Plansza gotowa")) {
                		setNotSetYet(false);
                	}
                	
                	if(line.length() == 5) {
                		i = (int)(line.charAt(0))-48; //because of ASCII
                		j = (int)(line.charAt(4))-48;
                		changeTurn(true);
                	}             
                }
            }
        } catch (IOException ex) {
            Logger.getLogger(BattleshipListener.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
