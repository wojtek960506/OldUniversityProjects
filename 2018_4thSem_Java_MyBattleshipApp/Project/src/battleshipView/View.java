package battleshipView;

import java.awt.Color;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

import battleshipModel.ShipDirection;


public class View extends JFrame{

	private static final long serialVersionUID = 1L;
	
	public static final int FRAME_HEIGHT = 600; //tymczasowo, zeby łatwiej było zmniejszać
	
	private Board playerBoard = new Board(45,80,true);
	private Board enemyBoard = new Board(550,80,false);
	private MainMenu mainMenu = new MainMenu();
	
	private boolean ifBattle;
	
	public void changePlayerNumber(int a) {
		mainMenu.changePlayerNumber(a);
	}
	
	public int getPlayerNumber() {
		return mainMenu.getPlayerNumber();
	}
	
	public boolean getIfBattle() {
		return ifBattle;
	}
	
	public void setIfBattle(boolean b) {
		ifBattle = b;
	}
	
	public Board getPlayerBoard() {
		return playerBoard;
	}
	
	public void viewAfterSettingShips() {
		mainMenu.viewAfterSettingShips();
	}
	
	public ShipDirection getDirectionType() {
		return mainMenu.getDirectiontype();
	}
	
	public Board getEnemyBoard() {
		return enemyBoard;
	}
	
	public View() {
		ifBattle = false;
		setLayout(null);
		setResizable(false);
		setBounds(0,0,1000,FRAME_HEIGHT);
		setBackground(Color.BLACK);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
		playerBoard.setVisible(false);
		enemyBoard.setVisible(false);
		add(playerBoard);
		add(enemyBoard);
		add(mainMenu);
//		addMouseListener(playerBoard);
	//	addMouseListener(enemyBoard);
		mainMenu.loadMainScreen();
	}
	
	public void setPlayerNumber() {
		mainMenu.setPlayerNumber();
	}
	
	public void hideListenPortButton() {
		mainMenu.hideListenPortButton();
	}
	
	public void hitYour(int i, int j) {
		playerBoard.hit(i,j);
	}
	
	public void missYour(int i, int j) {
		playerBoard.miss(i,j);
	}
	
	public void hit(int i, int j) {
		enemyBoard.hit(i,j);
	}
	
	public void miss(int i, int j) {
		enemyBoard.miss(i,j);
	}
	
	public void writeSth() {
		mainMenu.writeSth();
		repaint();
	}
	
	public int getListenPort() {
		return mainMenu.getListenPort();
	}
	
	public int getTransmitPort() {
		return mainMenu.getTransmitPort();
	}
	
	public String getHostname() {
		return mainMenu.getHostname();
	}
	
	public void setShip(int i, int j) {
		playerBoard.setShip(i, j);
		repaint();
	}
	
	public void afterStart() {
		mainMenu.afterStart();
		playerBoard.setVisible(true);
		enemyBoard.setVisible(true);
	}
	
	public void afterQuit() {
		mainMenu.afterQuit();
	}
	
	public void afterConnect() {
		mainMenu.afterConnect();
	}
	
	public void setShipDirection() {
		mainMenu.setShipDirection();
	}
	
	public void addStartListener(ActionListener listenForStartGame) {
		mainMenu.addStartListener(listenForStartGame);
	}
	
	public void addConnectListener(ActionListener listenForStartGame) {
		mainMenu.addConnectListener(listenForStartGame);
	}

	public void addQuitListener(ActionListener listenForQuitGame) {
		mainMenu.addQuitListener(listenForQuitGame);
	}
	
	public void addSetShipDirectionListener(ActionListener listenForQuitGame) {
		mainMenu.addSetShipDirectionListener(listenForQuitGame);
	}
	
	public void addListenPortListener(ActionListener listenForListenPort) {
		mainMenu.addListenPortListener(listenForListenPort);
	}
	
	public void addPlayerNumberListener(ActionListener listenForPlayerNumber) {
		mainMenu.addPlayerNumberListener(listenForPlayerNumber);
	}
	
	public void displayErrorMessage(String errorMessage){
		JOptionPane.showMessageDialog(this, errorMessage);		
	}
}
