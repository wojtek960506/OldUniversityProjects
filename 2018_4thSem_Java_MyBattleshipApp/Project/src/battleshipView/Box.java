package battleshipView;





//import java.awt.Color;

import javax.swing.JButton;




/**
 * klasa do rysowania plansz i przycisków na planszy
 */
public class Box extends JButton{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	public static final int X_ORIGIN_PLAYER = 20; // X coordinate of the top left of player board
	public static final int Y_ORIGIN_PLAYER = 20; // Y coordinate of the top left of player board
	public static final int X_ORIGIN_ENEMY = 470; // X coordinate of the top left of enemy board
	public static final int Y_ORIGIN_ENEMY = 220; // Y coordinate of the top left of player board
	public static final int TILE_SIZE = 33; // Size of the tile spaces
	public static final int BORDER_SIZE = 5; // size of the border between spaces
	
	//private Color c;
	private JButton button;
	public int mCoordinate;
	public int nCoordinate;
	
	public Box(int m, int n) {
		button = new JButton("");
		button.setVisible(true);
		try {
			set_mCoordinate(m);
			set_nCoordinate(n);
		}
		catch (ArrayIndexOutOfBoundsException e){
			System.out.println("ArrayIndexOutOfBoundException " + e);			
		}
	}
	
	/**
	 * 	getter dla współrzędnej m
	 */
	public int get_mCoordinate() {
		return mCoordinate;
	}

	/**
	 * 	setter dla współrzędnej m
	 */
	public void set_mCoordinate(int mCoordinate) {
		this.mCoordinate = mCoordinate;
	}
	
	/**
	 * 	getter dla współrzędnej n
	 */
	public int get_nCoordinate() {
		return nCoordinate;
	}

	/**
	 * 	setter dla współrzędnej n
	 */
	public void set_nCoordinate(int nCoordinate) {
		this.nCoordinate = nCoordinate;
	}
	
	/*public void addSetShipListener(ActionListener listenForStartGame) {
	button.addActionListener(listenForStartGame);
	}*/

}
