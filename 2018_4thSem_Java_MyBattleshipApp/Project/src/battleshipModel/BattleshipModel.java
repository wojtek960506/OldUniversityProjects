package battleshipModel;


/**
 * Klasa obsługująca główny model gry
 */
public class BattleshipModel {
	
	public static final int BOARD_SIZE = 10;
	public static final int SHIPS_NUMBER = 9;
	public static final int LARGEST_SHIP_LENGTH = 5;
	public static final int SHIP5 = 1; //number of battleships of length 5
	public static final int SHIP4 = 2; //number of battleships of length 4
	public static final int SHIP3 = 2; //number of battleships of length 3
	public static final int SHIP2 = 2; //number of battleships of length 2
	public static final int SHIP1 = 2; //number of battleships of length 1

	public BoxType board[][];
	
	public int boardWithPlacedShips[][];
	public int shipsPlaced;
	
	public Ship[] ships;
	
	/**
	 * zmienna określająca ile statków pozostało na planszy
	 */
	private int shipsLeft;
	
	/**
	 * getter dla zmiennej shipsLeft
	 */
	public int getShipsLeft() {
		return shipsLeft;
	}

	/**
	 * setter dla zmiennej shipsLeft
	 */
	public void setShipsLeft(int shipsLeft) {
		this.shipsLeft = shipsLeft;
	}

	/**
	 * konstruktor klasy. Tworzona jest w nim plansza oraz statki
	 */
	public BattleshipModel () {
		int i,j;
		setShipsLeft(SHIPS_NUMBER);
		shipsPlaced = 0; //this will help me to set numbers in boardWithPlacedShips
		
		board = new BoxType[BOARD_SIZE][BOARD_SIZE];
		boardWithPlacedShips = new int[BOARD_SIZE][BOARD_SIZE];
		ships = new Ship[SHIPS_NUMBER];
		
		//initialization of ships
		for(i = 0 ; i < SHIPS_NUMBER ; i++) {
			ships[i] = new Ship();
		}
		
		//here I set number and type of battleships in the game
		for(i=0 ; i < SHIP5 ; i++ ) {
			ships[i].setShipLength(5);
		}
		for( ; i < SHIP5 + SHIP4 ; i++ ) {
			ships[i].setShipLength(4);
		}
		for( ; i < SHIP5 + SHIP4 + SHIP3 ; i++) {
			ships[i].setShipLength(3);
		}
		for( ; i < SHIP5 + SHIP4 + SHIP3 + SHIP2 ; i++) {
			ships[i].setShipLength(2);
		}
		for( ; i < SHIP5 + SHIP4 + SHIP3 + SHIP2 + SHIP1 ; i++) {
			ships[i].setShipLength(1);
		}
		
		//Before the game Board is empty
		for(i = 0 ; i < BOARD_SIZE ; i++) {
			for(j = 0 ; j < BOARD_SIZE ; j++) {
				board[i][j] = BoxType.EMPTY;
			}
		}
		
		//before the game we didn't set any board on our additional board
		for(i = 0 ; i < BOARD_SIZE ; i++) {
			for(j = 0 ; j < BOARD_SIZE ; j++) {
				boardWithPlacedShips[i][j] = -1; //there is no possible to find ship[-1]
			}
		}
	}
	
	/**
	 * metoda obsługująca strzał w dane pole. Zwraca rodzaj tego pola
	 */
	public BoxType shoot(int m, int n) {
		int shipNumber;
		int i,j;
		
		if(m < 0 || m > BOARD_SIZE - 1 || n < 0 || n > BOARD_SIZE - 1) //wrong coordinates
			return BoxType.HIT;
		
		switch (board[m][n]) {
			case EMPTY:
				board[m][n] = BoxType.MISS;
				return BoxType.EMPTY;
			case MISS:			//I will make sure that this situation will not be possible
				//System.out.println("miss");
				return BoxType.MISS;
			case HIT:			//I will make sure that this situation will not be possible
				//System.out.println("hit");
				return BoxType.HIT;
			case POSITIONED:
				board[m][n] = BoxType.HIT;
				shipNumber = boardWithPlacedShips[m][n];
				System.out.println("ShipNumber: " + shipNumber);
				System.out.println("First M: " + ships[shipNumber].firstM);
				System.out.println("First N: " + ships[shipNumber].firstN);
				System.out.println("Last M: " + ships[shipNumber].lastM);
				System.out.println("Last N: " + ships[shipNumber].lastN);
				if(ships[shipNumber].direction == ShipDirection.VERTICAL);
					System.out.println("Ship Direction: VERTICAL");
				if(ships[shipNumber].direction == ShipDirection.HORIZONTAL);
					System.out.println("Ship Direction: HORIZONTAL");
				ships[shipNumber].hitShip();
				
				if(ships[shipNumber].sunkShip()) { //if ship is sunk fields around it are not possible anymore to shoot
					
					if(ships[shipNumber].direction == ShipDirection.VERTICAL) {
						//three boxes above the ship
						if(!(ships[shipNumber].firstM - 1 < 0) ) {
							if(!(ships[shipNumber].firstN - 1 < 0) )
								board[ships[shipNumber].firstM - 1][ships[shipNumber].firstN - 1] = BoxType.MISS;
							board[ships[shipNumber].firstM - 1][ships[shipNumber].firstN] = BoxType.MISS;
							if(!(ships[shipNumber].firstN + 1 > BOARD_SIZE - 1))
								board[ships[shipNumber].firstM - 1][ships[shipNumber].firstN + 1] = BoxType.MISS;
						}
						//three boxes under the ship
						if(!(ships[shipNumber].lastM + 1 > BOARD_SIZE - 1)) {
							if(!(ships[shipNumber].firstN - 1 < 0) )
								board[ships[shipNumber].lastM + 1][ships[shipNumber].firstN - 1] = BoxType.MISS;
							board[ships[shipNumber].lastM + 1][ships[shipNumber].firstN] = BoxType.MISS;
							if(!(ships[shipNumber].lastN + 1 > BOARD_SIZE - 1))
								board[ships[shipNumber].lastM + 1][ships[shipNumber].firstN + 1] = BoxType.MISS;
						}
						//boxes on left and right side of ship
						for(i = ships[shipNumber].firstM ; i < ships[shipNumber].lastM + 1 ; i ++) {
							if(!(ships[shipNumber].firstN - 1 < 0) )
								board[i][ships[shipNumber].firstN - 1] = BoxType.MISS;
							if(!(ships[shipNumber].firstN + 1 > BOARD_SIZE - 1))
								board[i][ships[shipNumber].firstN + 1] = BoxType.MISS;
						}
					}
					if(ships[shipNumber].direction == ShipDirection.HORIZONTAL) {
						//boxes on left side of ship
						if(!(ships[shipNumber].firstN - 1 < 0)) {
							if(!(ships[shipNumber].firstM - 1 < 0))
								board[ships[shipNumber].firstM - 1][ships[shipNumber].firstN - 1] = BoxType.MISS;
							board[ships[shipNumber].firstM][ships[shipNumber].firstN - 1] = BoxType.MISS;
							if(!(ships[shipNumber].firstM + 1 > BOARD_SIZE - 1))
								board[ships[shipNumber].firstM + 1][ships[shipNumber].firstN - 1] = BoxType.MISS;
						}
						//boxes on right side of ship
						if(!(ships[shipNumber].lastN + 1 > BOARD_SIZE - 1)) {
							if(!(ships[shipNumber].firstM - 1 < 0))
								board[ships[shipNumber].firstM - 1][ships[shipNumber].lastN + 1] = BoxType.MISS;
							board[ships[shipNumber].firstM][ships[shipNumber].lastN + 1] = BoxType.MISS;
							if(!(ships[shipNumber].firstM + 1 > BOARD_SIZE - 1))
								board[ships[shipNumber].firstM + 1][ships[shipNumber].lastN + 1] = BoxType.MISS;
						}
						//boxes above and under the ship
						for(j = ships[shipNumber].firstN ; j < ships[shipNumber].lastN + 1 ; j ++) {
							if(!(ships[shipNumber].firstM - 1 < 0) )
								board[ships[shipNumber].firstM - 1][j] = BoxType.MISS;
							if(!(ships[shipNumber].firstM + 1 > BOARD_SIZE - 1))
								board[ships[shipNumber].firstM + 1][j] = BoxType.MISS;
						}
					}
							
					setShipsLeft(getShipsLeft() - 1);
				}			
				return BoxType.POSITIONED;
			
			default:
				return BoxType.HIT;	
		}
			
		
	}
	
	/**
	 * metoda obsługująca ustawianie statku na planszy. Zwraca fałsz, jeżeli nie udało się ustawić
	 */
	boolean setShipPosition(Ship ship, int fM, int fN, ShipDirection direction) {
		int i,j; //to move on a board
		
		if(isValidPoint(ship,fM,fN,direction)) {
			
			ship.firstM = fM;
			ship.firstN = fN;
			ship.direction = direction;
			
			
			if(direction == ShipDirection.HORIZONTAL) {
				ship.lastM = fM;
				ship.lastN = fN + ship.length - 1;
				
				for(j = ship.firstN ; j < ship.lastN + 1 ; j++) {
					board[ship.firstM][j] = BoxType.POSITIONED;
					boardWithPlacedShips[ship.firstM][j] = shipsPlaced;
				}
					
					
			}
			
			if(direction == ShipDirection.VERTICAL) { //direction is horizontal
				ship.lastM = fM + ship.length - 1;
				ship.lastN = fN;
				
				for(i = ship.firstM ; i < ship.lastM + 1 ; i++) {
					board[i][ship.firstN] = BoxType.POSITIONED;
					boardWithPlacedShips[i][ship.firstN] = shipsPlaced;
				}
			}
			shipsPlaced++; //we will set ship on board and I have to increment it now because this number mean number of ship in its table
			return true;
		}
		return false;
	}
	
	/**
	 * kolejna metoda obsługująca ustawianie statku na planszy. Zwraca fałsz, jeżeli nie udało się ustawić
	 */
	public boolean setShipPosition(int fM, int fN, ShipDirection direction) {
			//Normalna wersja dla statkow tak jak ma byc kolejnosc
			if(setShipPosition(ships[shipsPlaced], fM, fN, direction))
				return true;
			return false;
			//*/
		}
	
	/**
	 * metoda określająca czy w danym punkcie jest możliwe ustawienie statku
	 */
	boolean isValidPoint(Ship ship, int fM, int fN, ShipDirection direction) {
		int i,j;
		
		if(direction == ShipDirection.VERTICAL) {
			if(fM < 0 || fN < 0 || fM + ship.length-1 > BOARD_SIZE-1 || fN > BOARD_SIZE-1 || fM > BOARD_SIZE-1) {
				return false;
			}
		
		
			for(i=fM-1 ; i < fM + ship.length + 1 ; i++) {
				
				if(i==fM-1) {
					if(fM-1 < 0 )
						continue;
				}
				
				if(i==fM + ship.length) {
					if(fM + ship.length > BOARD_SIZE - 1) 
						continue;
				}
				
				for(j = fN-1 ; j < fN + 2 ; j++) { //there will be three rows
				
					if(j==fN-1) {
						if(fN-1 < 0) 
							continue;
					}
					
					if(j==fN + 1) {
						if(fN+1 > BOARD_SIZE - 1) {
							continue;
						}
					}
					
					if(board[i][j] == BoxType.POSITIONED)
						return false;
				}
			}
		}
		
		if(direction == ShipDirection.HORIZONTAL) {
			if(fM < 0 || fN < 0 || fN + ship.length-1 > BOARD_SIZE-1 || fN > BOARD_SIZE-1 || fM > BOARD_SIZE-1) {
				return false;
			}
			
			for(i=fM-1 ; i < fM + 2 ; i++) {
				
				if(i==fM-1) {
					if(fM-1 < 0 )
						continue;
				}
				
				if(i==fM + 1) {
					if(fM + 1 > BOARD_SIZE - 1) 
						continue;
				}
				
				for(j = fN-1 ; j < fN + ship.length + 1 ; j++) {
				
					if(j==fN-1) {
						if(fN-1 < 0) 
							continue;
					}
					
					if(j==fN + ship.length) {
						if(fN + ship.length > BOARD_SIZE - 1) {
							continue;
						}
					}
					
					if(board[i][j] == BoxType.POSITIONED)
						return false;
				}
			}
			
		}	
		return true;
	}
	
	/**
	 * pomocnicza metoda wyświetlająca statek na planszy
	 */
	public void printBoard() {
		int i,j;
		
		System.out.println("Main Board.");
		
		for(i = 0 ; i < BOARD_SIZE ; i++) {
			for(j = 0 ; j < BOARD_SIZE ; j++) {
				switch(board[i][j]) {
				case EMPTY:
					System.out.print("0 ");
					break;
				case POSITIONED:
					System.out.print("1 ");
					break;
				case HIT:
					System.out.print("2 ");
					break;
				case MISS:
					System.out.print("3 ");
					break;
				default:
					System.out.println("Something is wrong with printing board.");
				}
			}
			System.out.println("");
			
		}
		System.out.println("");
		System.out.println("Additional Board");
		for(i = 0 ; i < BOARD_SIZE ; i++) {
			for(j = 0 ; j < BOARD_SIZE ; j++) {
				if(boardWithPlacedShips[i][j] == -1)
					System.out.print("N ");
				else {
					System.out.print(boardWithPlacedShips[i][j] + " ");
				}
			}
			System.out.println("");
		}
		
		
	}
}
