package battleshipView;

import java.awt.Color;

import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.border.Border;

import battleshipModel.BattleshipModel;


/**
 * klasa rysująca plansze
 */
public class Board extends JPanel{
	
	private static final long serialVersionUID = 1L;
	
	public static final int X_ORIGIN_PLAYER = 6; // X coordinate of the top left of player board
	public static final int Y_ORIGIN_PLAYER = 6; // Y coordinate of the top left of player board
	public static final int X_ORIGIN_ENEMY = 470; // X coordinate of the top left of enemy board
	public static final int Y_ORIGIN_ENEMY = 220; // Y coordinate of the top left of player board
	public static final int TILE_SIZE = 35; // Size of the tile spaces
	public static final int BORDER_SIZE = 3; // size of the border between spaces
	
	int i,j;
	
	//private Border green = BorderFactory.createLineBorder(Color.GREEN);
	//private Border blue = BorderFactory.createLineBorder(Color.BLUE);
	private Border black = BorderFactory.createLineBorder(Color.BLACK);
	
	private Box[][] board = new Box[10][10];
	
	public Box[][] getBoard() {
		return board;
	}
    
	/**
	 * konstruktor klasy
	 */
    public Board(int x, int y, boolean ifYour) {
        setLayout(null);
        
        if(ifYour)
        	setBackground(Color.PINK);
        else
        	setBackground(Color.ORANGE);
        
        setBorder(black);
        setBounds(x,y,400,400);
        for(i = 0; i < BattleshipModel.BOARD_SIZE; i++) {
            for(j = 0 ; j < BattleshipModel.BOARD_SIZE ; j++) {
                board[i][j] = new Box(i,j);
                board[i][j].setBounds(X_ORIGIN_PLAYER + i + 1 + ((TILE_SIZE + BORDER_SIZE) * i),
											Y_ORIGIN_PLAYER + j + 1 + ((TILE_SIZE + BORDER_SIZE) * j),
											TILE_SIZE+(BORDER_SIZE/2)-1,
											TILE_SIZE+(BORDER_SIZE/2)-1);
                board[i][j].setBackground(Color.BLACK);
				board[i][j].setBorderPainted(false);
                add(board[i][j]);
            }
        }
        setVisible(true);
    }
    
    /**
	 * metoda obsługująca malowanie pola w przypadku trafienia
	 */
    public void hit(int i, int j) {
    	board[i][j].setBackground(Color.GREEN);
    }
    
    /**
	 * metoda obsługująca malowanie pola w przypadku chybienia
	 */
    public void miss(int i, int j) {
    	board[i][j].setBackground(Color.BLUE);
    }
    
    /**
	 * metoda obsługująca malowanie pola w przypadku ustawiania statku
	 */
    public void setShip(int i, int j) {
    	board[i][j].setBackground(Color.WHITE);
    }
    
}
