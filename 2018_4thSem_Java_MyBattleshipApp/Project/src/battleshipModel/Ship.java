package battleshipModel;


/**
 * klasa, w której przetrzymujemy informacje o pojedyńczym statku
 */
public class Ship {
	public int length;	// length of ship. It can be from interval [2,5];
	public int firstM;	// m coordinate of ship beginning
	public int firstN;	// n coordinate of ship beginning
	public int lastM;	// m coordinate of ship end
	public int lastN;	// n coordinate of ship end
	public int health;
	public ShipDirection direction; //it determine where ship is situated vertical(true) or horizontal(false)
	
	
	/**
	 * konstruktor domyślny statku
	 */
	Ship() {
		this.health = 0;
		this.length = 0;
		this.firstM = -1;
		this.firstN = -1;
		this.lastM = -1;
		this.lastN = -1;
		this.direction = ShipDirection.VERTICAL;
	}
	/**
	 * metoda pozwalająca zmienić długość statku
	 */
	void setShipLength(int length) {
		this.length = length;
		this.health = length;
	}
	/**
	 * metoda pozwalająca zmniejszyć długość statku po tym jak został trafiony
	 */
	void hitShip() {
		health--;
	}
	
	/**
	 * metoda pozwalająca określić czy statek został zatopiony
	 */
	public boolean sunkShip() {
		if(health == 0)
			return true;
		else
			return false;
	}
 	
	
}
