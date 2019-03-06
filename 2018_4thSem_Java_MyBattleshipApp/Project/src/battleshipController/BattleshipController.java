package battleshipController;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

//import javax.swing.JOptionPane;

import battleshipModel.*;
import battleshipView.*;


/**
 * To jest klasa kontrolera.
 * @author Wojciech
 *
 */
public class BattleshipController {
	/**
	 * słuchacz wiadomości
	 *
	 */
	private BattleshipListener listener;
	
	/**
	 * transmiter wiadomości
	 *
	 */
	private BattleshipTransmitter transmitter;
	
	/**
	 * zmienna modelu
	 */
	private BattleshipModel model;
	
	/**
	 * zmienna widoku
	 */
	private View view;
	
	/**
	 * zmienna planszy przeciwnika, 
	 */
	private BattleshipModel enemyModel;
	
	/**
	 * zmienna określająca, na którym porcie nasłuchujemy
	 */
	private Integer listenPort;
	
	/**
	 * zmienna określająca, na którym porcie transmitujemy
	 */
	private Integer transmitPort;
	
	/**
	 * zmienna określająca, nazwę serwera
	 */
	private String hostname;
	
	/**
	 * zmienna określająca współrzędną X strzału
	 */
	private int shootX;
	
	/**
	 * zmienna określająca współrzędną Y strzału
	 */
	private int shootY;
	
	/**
	 * zmienna określająca numer gracza
	 */
	private int playerNumber = 1;
	
	int i = 0;
	
	/**
	 * zmienna określająca czy strzał został wykonany
	 */
	private boolean ifShot = false; //it is used in startShooting() and battleOn() to check if there was a shot
	
	/**
	 * zmienna określająca czy główna rozgrywka się rozpoczęła
	 */
	public boolean ifBattle = false;
	
	/**
	 * setter dla zmiennej ifShot
	 * @param b
	 */
	public void setIfShot(boolean b) {
		ifShot = b;
	}
	/**
	 * setter dla zmiennej ifBattle
	 * @param b
	 */
	public void setIfBattle(boolean b) {
		ifBattle = b;
	}
	
	/**
	 * konstruktor kontrolera
	 * @param view
	 * @param theModel
	 */
	public BattleshipController(View view, BattleshipModel theModel)
	{
		this.model = theModel;		
		this.view = view;
		
		enemyModel = new BattleshipModel();
		
		//listeners for buttons
		view.addStartListener(new StartListener());
		view.addQuitListener(new QuitListener());
		view.addConnectListener(new ConnectListener());
		view.addSetShipDirectionListener(new SetShipDirectionListener());
		view.addListenPortListener(new ListenPortListener());
		view.addPlayerNumberListener(new PlayerNumberListener());
	}
	

	/**
	 * funkcja, która obsługuje główną rozgrywkę
	 */
	public void battleOn(){
		initBoardButtons();
		
		
		while( !ifBattle )	{
			System.out.print("");
		}
		
			if(playerNumber == 2) {
		
			transmitter = new BattleshipTransmitter("Plansza gotowa", hostname , transmitPort); //wysylam wiadomosc gdzie strzelam
    		transmitter.start();
			}
		
		if(playerNumber == 1) { 
			while(listener.ifNotSetYet())
				System.out.print("");
			}		
		for(int i1 = 0 ; i1 < BattleshipModel.BOARD_SIZE ; i1++) {
			for(int j1 = 0 ; j1 < BattleshipModel.BOARD_SIZE ; j1++) {
				switch(model.board[i1][j1]) {
				case EMPTY:
					transmitter = new BattleshipTransmitter(i1 + " , " + j1 + " , 0", hostname , transmitPort); //wysylam wiadomosc gdzie strzelam
		    		transmitter.start();
					
		    		break;
				case HIT:
					transmitter = new BattleshipTransmitter(i1 + " , " + j1 + " , " + 2, hostname , transmitPort); //wysylam wiadomosc gdzie strzelam
		    		transmitter.start();
					break;
				case MISS:
					transmitter = new BattleshipTransmitter(i1 + " , " + j1 + " , 3", hostname , transmitPort); //wysylam wiadomosc gdzie strzelam
		    		transmitter.start();
		    		break;
				case POSITIONED:
					transmitter = new BattleshipTransmitter(i1 + " , " + j1 + " , " + 1, hostname , transmitPort); //wysylam wiadomosc gdzie strzelam
		    		transmitter.start();
					break;
				default:
					break;
				}
				try{
					Thread.sleep(5);
				}
				catch(InterruptedException e) {	
				}
			}
		}
		
		for(int i1 = 0 ; i1 < BattleshipModel.BOARD_SIZE ; i1++) {
			for(int j1 = 0 ; j1 < BattleshipModel.BOARD_SIZE ; j1++) {
				enemyModel.board[i1][j1] = listener.board[i1][j1];
			}
        }
		
		
		for(int i1 = 0 ; i1 < BattleshipModel.BOARD_SIZE ; i1++) {
			for(int j1 = 0 ; j1 < BattleshipModel.BOARD_SIZE ; j1++) {
				if(model.boardWithPlacedShips[i1][j1] != -1) {
					transmitter = new BattleshipTransmitter(i1 + " , " + j1 + " , " + model.boardWithPlacedShips[i1][j1] + ".", hostname , transmitPort); //wysylam wiadomosc gdzie strzelam	
					transmitter.start();
				}
				else {
					transmitter = new BattleshipTransmitter(i1 + " , " + j1 + " , " +  "N.", hostname , transmitPort); //wysylam wiadomosc gdzie strzelam	
					transmitter.start();
				}
				try{
					Thread.sleep(5);
				}
				catch(InterruptedException e) {	
				}
			}
		}
		
		for(int i1 = 0 ; i1 < BattleshipModel.BOARD_SIZE ; i1++) {
			for(int j1 = 0 ; j1 < BattleshipModel.BOARD_SIZE ; j1++) {
				enemyModel.boardWithPlacedShips[i1][j1] = listener.boardWithPlacedShips[i1][j1];
			}
        }
		
		for(int i1 = 0 ; i1 < BattleshipModel.SHIPS_NUMBER ; i1++) {
			int l = model.ships[i1].length;
			int fM = model.ships[i1].firstM;
			int fN = model.ships[i1].firstN;
			int lM = model.ships[i1].lastM;
			int lN = model.ships[i1].lastN;
			int h = model.ships[i1].health;
			int d;
			if(model.ships[i1].direction == ShipDirection.VERTICAL)
				d = 1; //vertical
			else {
				d = 2; //horizontal
			}
			transmitter = new BattleshipTransmitter(l + "," + fM + "," + fN + "," + lM + "," + lN + "," + h + "," + d + "," + i1, hostname , transmitPort); //wysylam wiadomosc gdzie strzelam	
			transmitter.start(); //l,fM,fN,lM,lN,h,d
		}
		
		for(int i1 = 0 ; i1 < BattleshipModel.SHIPS_NUMBER ; i1++) {
			enemyModel.ships[i1].direction = listener.shipsArray[i1].direction;
			enemyModel.ships[i1].firstM = listener.shipsArray[i1].firstM;
			enemyModel.ships[i1].firstN = listener.shipsArray[i1].firstN;
			enemyModel.ships[i1].health = listener.shipsArray[i1].health;
			enemyModel.ships[i1].lastM = listener.shipsArray[i1].lastM;
			enemyModel.ships[i1].lastN = listener.shipsArray[i1].lastN;
			enemyModel.ships[i1].length = listener.shipsArray[i1].length;
		}
		
		
		try{
			Thread.sleep(1000);
		}
		catch(InterruptedException e) {	
		}
		
		System.out.println("my board");
		System.out.println("");
		model.printBoard();
		System.out.println("enemy board");
		System.out.println("");
		enemyModel.printBoard();
		
		while(true) {		
			
			if(playerNumber == 1) {
	    		
				try{
					Thread.sleep(100);
				}
				catch(InterruptedException e) {	
				}
				if(ifShot) {
					transmitter = new BattleshipTransmitter(shootX + " , " + shootY , hostname , transmitPort); //wysylam wiadomosc gdzie strzelam
		    		transmitter.start(); //wlaczam transmitter, żeby wyslac strzal i zaraz go wylaczam
		    		try{
						Thread.sleep(100);
					}
					catch(InterruptedException e) {	
					}
		    		
		    		playerNumber = 2; //nie moj ruch
		    		listener.changeTurn(false);  //ustawiam sie, ze nie jest moj ruch
		    		
		    		System.out.println("I have shot ( " + shootX + " , " +  shootY + " )");
		    		setIfShot(false); //we set it at true in shootListener, so after shot we have to make it false
		    		listener.setIfMessageBack(true); //we have shot and now we want information about it back
				}
	    	}
			else {
				try{
					Thread.sleep(100);
				}
				catch(InterruptedException e) {	
				}
				
				if(listener.isYourTurn()) {
					
					
					
					playerNumber = 1;
	    		}
			}
			
			
			if(enemyModel.getShipsLeft() == 0) {
				transmitter = new BattleshipTransmitter("You win", hostname , transmitPort);
				transmitter.start();
				System.out.println("I lost");
				break;
			}
			
			if(listener.getResult()) {
				System.out.println("I won");
				break;
			}
		}
	}

//------------------------------------------------------------------------------------------------------------------------	
	/**
	 * klasa do obsługi przycisku do zmieniania numeru gracza
	 *
	 */
	class PlayerNumberListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			view.setPlayerNumber();
			if(playerNumber == 1) {
				playerNumber = 2; //when we click on this button we change its state
				listener.changeTurn(false);
			}
			
			else {
				playerNumber = 1; //when we click on this button we change its state
				listener.changeTurn(true);
			}
		}
	}
	
	/**
	 * klasa do obsługi przycisku do rozpoczęcia słuchania
	 *
	 */
	class ListenPortListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			try {
				listenPort = view.getListenPort();
				transmitPort = view.getTransmitPort();
				hostname = view.getHostname();
				
				if(String.valueOf(listenPort).length() != 4 || String.valueOf(transmitPort).length() != 4 || (int)listenPort == (int)transmitPort)
					throw new NumberFormatException();
				
				view.hideListenPortButton();
				
				listener = new BattleshipListener(listenPort);
		
				listener.start();
			}
			catch(NumberFormatException ex) {
				view.displayErrorMessage("Listen Port and Transmit Port must be Integers with a length of 4. They can't also be the same");
			}
		}
	}
	
	/**
	 * klasa do obsługi przycisku do ustawienia kierunku ustawienia statku
	 *
	 */
	class SetShipDirectionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			view.setShipDirection();
		}
	}
	
	/**
	 * klasa do obsługi przycisku rozpoczęcia gry
	 *
	 */
	class StartListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			view.afterStart();
			transmitter = new BattleshipTransmitter("Hello. How are you doing?", hostname , transmitPort); //wysylam wiadomosc gdzie strzelam
    		transmitter.start(); //wlaczam transmitter, żeby wyslac strzal i zaraz go wylaczam
		}
	}
	
	/**
	 * klasa do obsługi przycisku połączenia
	 *
	 */
	class ConnectListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {	
			view.afterConnect();
		}
	}
	
	/**
	 * klasa do obsługi wyjścia wyjścia gry
	 *
	 */
	class QuitListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			view.afterQuit();
		}
	}
	
	
	/**
	 * metoda do inicjalizacji działania przycisków na planszy gracza
	 *
	 */
	public void initBoardButtons() {
        int i, j;
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                ClickListener ij = new ClickListener(i,j) {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        if(model.shipsPlaced < BattleshipModel.SHIPS_NUMBER) {                        	
                        	communicate(this);
                        }
                        if(model.shipsPlaced == BattleshipModel.SHIPS_NUMBER) {
                        	view.viewAfterSettingShips();
                        	setIfBattle(true);
                        }
                    }
                };
                ShotListener ij2 = new ShotListener(i,j) {
                	@Override
                    public void actionPerformed(ActionEvent e) {
                        if(ifBattle)	
                			startShooting(this);
                    }
                };
                view.getPlayerBoard().getBoard()[i][j].addActionListener(ij);
                view.getEnemyBoard().getBoard()[i][j].addActionListener(ij2);
            }
        }
    }
	
	/**
	 * metoda do inicjalizacji działania przycisków na planszy gracza
	 *
	 */
	public void startShooting(ShotListener shotListener) {
		if(listener.isYourTurn()) {
			shootX = shotListener.getI(); //odczytuje wspolrzedna strzalu
			shootY = shotListener.getJ(); //odczytuje wspolrzedna strzalu
			
			int i = shotListener.getI();
			int j = shotListener.getJ();
			
			BoxType bT = enemyModel.shoot(j, i);
    		if(bT == BoxType.POSITIONED) {
				view.hit(i,j);
			}
			if(bT == BoxType.EMPTY){
				view.miss(i,j);
			}
			if(bT != BoxType.HIT && bT != BoxType.MISS)
				setIfShot(true);
		}
	}
	
	/**
	 * metoda do wysterowania działania przycisków na planszy gracza
	 *
	 */
	public void communicate(ClickListener clickListener) {
        if(model.setShipPosition(clickListener.getJ(), clickListener.getI(), view.getDirectionType())) {
        	if(true) {
	        	int i = clickListener.getI();
	        	int j = clickListener.getJ();
	        	for(int a = 0 ; a < model.ships[model.shipsPlaced - 1].length ; a++ ) {
	    			if(model.ships[model.shipsPlaced - 1].direction == ShipDirection.VERTICAL) {
	    				view.setShip(i,j+a);
	    			}
	    			else {
	    				view.setShip(i+a,j);
	    			}
	    		}
        	}
        }
    }
	
	/**
	 * klasa do inicjalizacji działania przycisków na planszy przeciwnika
	 *
	 */
	abstract class ClickListener implements ActionListener {
	    private int i;
	    private int j;
	    
	    ClickListener(int i, int j) {
	        this.i = i;
	        this.j = j;
	    }
	    
	    public int getI() {
	        return i;
	    }

	    public int getJ() {
	        return j;
	    }
	}
	
	/**
	 * klasa do wysterowania kliknięć na planszy przeciwnika
	 *
	 */
	abstract class ShotListener implements ActionListener {
		private int i;
	    private int j;
	    
	    ShotListener(int i, int j) {
	        this.i = i;
	        this.j = j;
	    }
	    
	    public int getI() {
	        return i;
	    }

	    public int getJ() {
	        return j;
	    }
	}
}
