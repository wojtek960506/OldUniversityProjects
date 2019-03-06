package battleshipView;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import battleshipModel.ShipDirection;


public class MainMenu extends JPanel {
	
	private static final long serialVersionUID = 1L;
	
	private ShipDirection directionType = ShipDirection.HORIZONTAL;
	
	private int playerNumber = 1;
	
	public int getPlayerNumber() {
		return playerNumber;
	}
	
	public void changePlayerNumber(int a) {
		playerNumber = a;
	}
	
	public ShipDirection getDirectiontype() {
		return directionType;
	}
	
	private JButton startGame;
	private JButton quitGame;
	private JLabel hostnameLabel;
	private JTextField hostnameTextField;
	private JLabel listenPortLabel;
	private JTextField listenPortTextField;
	private JLabel transmitPortLabel;
	private JTextField transmitPortTextField;
	private JButton connect;
	private JLabel playerBoardLabel;
	private JLabel enemyBoardLabel;
	private JButton shipDirectionButton;
	private JButton listenPortButton;
	private JButton playerNumberButton;
	
	private JLabel writeSth;
	
	Font font1 = new Font("Courier", Font.BOLD,70);
    Font font2 = new Font("Courier", Font.PLAIN, 25);
    Font font3 = new Font("Courier", Font.BOLD, 50);
	
	public MainMenu() {
		setLayout(null);
		setBackground(Color.GRAY);
		setBounds(0,0,1000,View.FRAME_HEIGHT);
		setVisible(true);
	}
		

	
	public void loadMainScreen() {
		listenPortButton = new JButton("LISTEN");
		listenPortButton.setBounds(300,20,300,100);
		listenPortButton.setVisible(true);
		listenPortButton.setFont(font1);
		listenPortButton.setOpaque(false);
		listenPortButton.setContentAreaFilled(false);
		listenPortButton.setBorderPainted(false);
		listenPortButton.setForeground(Color.BLACK);
		
		playerNumberButton = new JButton("PLAYER 1");
		//playerNumberButton.setBounds(680,35,280,70);
		playerNumberButton.setBounds(200,240,500,100);
		playerNumberButton.setVisible(true);
		playerNumberButton.setFont(font1);
		playerNumberButton.setOpaque(true);
		playerNumberButton.setContentAreaFilled(true);
		playerNumberButton.setBorderPainted(false);
		playerNumberButton.setForeground(Color.WHITE);
		playerNumberButton.setBackground(Color.BLACK);
		
		startGame = new JButton("START GAME");
		startGame.setBounds(200,20,500,100);
		startGame.setVisible(true);
		startGame.setFont(font1);
		startGame.setOpaque(false);
		startGame.setContentAreaFilled(false);
		startGame.setBorderPainted(false);
		startGame.setForeground(Color.BLACK);
		
		quitGame = new JButton("QUIT");
		quitGame.setSize(500, 100);
		quitGame.setLocation(200, 450);
		quitGame.setVisible(true);
		quitGame.setFont(font1);
		quitGame.setOpaque(false);
		quitGame.setContentAreaFilled(false);
		quitGame.setBorderPainted(false);
		quitGame.setForeground(Color.BLACK);
		
		connect = new JButton("CONNECT");
		connect.setSize(400,100);
		connect.setLocation(250,20);
		connect.setVisible(true);
		connect.setFont(font1);
		connect.setOpaque(false);
		connect.setContentAreaFilled(false);
		connect.setBorderPainted(false);
		connect.setForeground(Color.BLACK);
		
		hostnameLabel = new JLabel("HOSTNAME");
		hostnameLabel.setSize(200,50);
		hostnameLabel.setLocation(310,150);
		hostnameLabel.setVisible(true);
		hostnameLabel.setFont(font2);
		hostnameLabel.setForeground(Color.BLACK);
		
		hostnameTextField = new JTextField(30);
		hostnameTextField.setText("localhost");
		hostnameTextField.setSize(195,50);
		hostnameTextField.setLocation(460,150);
		hostnameTextField.setVisible(true);
		hostnameTextField.setFont(font2);
		hostnameTextField.setForeground(Color.BLACK);
		
		listenPortLabel = new JLabel("LISTEN PORT");
		listenPortLabel.setSize(200,50);
		listenPortLabel.setLocation(292,250);
		listenPortLabel.setVisible(true);
		listenPortLabel.setFont(font2);
		listenPortLabel.setForeground(Color.BLACK);
		
		listenPortTextField = new JTextField(10);
		listenPortTextField.setText("6000");
		listenPortTextField.setSize(100,50);
		listenPortTextField.setLocation(460,250);
		listenPortTextField.setVisible(true);
		listenPortTextField.setFont(font2);
		listenPortTextField.setForeground(Color.BLACK);
		
		transmitPortLabel = new JLabel("TRANSMIT PORT");
		transmitPortLabel.setSize(200,50);
		transmitPortLabel.setLocation(255,350);
		transmitPortLabel.setVisible(true);
		transmitPortLabel.setFont(font2);
		transmitPortLabel.setForeground(Color.BLACK);
		
		transmitPortTextField = new JTextField(10);
		transmitPortTextField.setText("6001");
		transmitPortTextField.setSize(100,50);
		transmitPortTextField.setLocation(460,350);
		transmitPortTextField.setVisible(true);
		transmitPortTextField.setFont(font2);
		transmitPortTextField.setForeground(Color.BLACK);
		
		playerBoardLabel = new JLabel("YOUR BOARD");
		playerBoardLabel.setSize(300,50);
		playerBoardLabel.setLocation(160,20);
		playerBoardLabel.setVisible(true);
		playerBoardLabel.setFont(font2);
		playerBoardLabel.setForeground(Color.BLACK);
		playerBoardLabel.setBackground(Color.YELLOW);
		
		enemyBoardLabel = new JLabel("ENEMY'S BOARD");
		enemyBoardLabel.setSize(300,50);
		enemyBoardLabel.setLocation(650,20);
		enemyBoardLabel.setVisible(true);
		enemyBoardLabel.setFont(font2);
		enemyBoardLabel.setForeground(Color.BLACK);
		enemyBoardLabel.setBackground(Color.YELLOW);
		
		shipDirectionButton = new JButton("HORIZONTAL");
		shipDirectionButton.setBounds(45,485,400,80);
		shipDirectionButton.setVisible(true);
		shipDirectionButton.setFont(font3);
		shipDirectionButton.setOpaque(true);
		shipDirectionButton.setContentAreaFilled(true);
		shipDirectionButton.setBorderPainted(false);
		shipDirectionButton.setForeground(Color.WHITE);
		shipDirectionButton.setBackground(Color.BLACK);
		
		
		//add(playerNumberButton);
		add(listenPortButton);
		//add(connect);
		add(quitGame);
		add(hostnameLabel);
		add(hostnameTextField);
		add(listenPortLabel);
		add(listenPortTextField);
		add(transmitPortLabel);
		add(transmitPortTextField);
		setBackground(Color.GRAY);
		setVisible(true);
		revalidate();
		repaint();
		
		writeSth = new JLabel("Ja zaczynam.");
		writeSth.setSize(50,50);
		writeSth.setLocation(500,300);
		writeSth.setVisible(true);
		writeSth.setFont(font2);
		writeSth.setForeground(Color.BLACK);
		
	}
	
	public void setPlayerNumber() {
		if(playerNumber == 1) {
			playerNumber = 2; //when we click on this button we change its state
			playerNumberButton.setText("PLAYER 2");
		}
		
		else {
			playerNumber = 1; //when we click on this button we change its state
			playerNumberButton.setText("PLAYER 1");
			
		}
	}
	
	public void hideListenPortButton() {
		remove(listenPortButton);
		remove(hostnameLabel);
		remove(hostnameTextField);
		remove(listenPortLabel);
		remove(listenPortTextField);
		remove(transmitPortLabel);
		remove(transmitPortTextField);
		
		add(connect);
		add(playerNumberButton);
		
		revalidate();
		repaint();
	}
	
	public void writeSth() {
		add(writeSth);
	}
	
	public int getListenPort() {
		return Integer.parseInt(listenPortTextField.getText());
	}
	
	public int getTransmitPort() {
		return Integer.parseInt(transmitPortTextField.getText());
	}
	
	public String getHostname() {
		return hostnameTextField.getText();
	}
	
	//this method is called when you finish setting ships on board
	public void viewAfterSettingShips() {
		remove(shipDirectionButton);
	}
	
	public void afterStart() {
		remove(startGame);
		remove(quitGame);
		add(playerBoardLabel);
		add(enemyBoardLabel);
		add(shipDirectionButton);
		revalidate();
		repaint();
	}
	
	public void afterConnect() {
		remove(connect);
		/*remove(hostnameLabel);
		remove(hostnameTextField);
		remove(listenPortLabel);
		remove(listenPortTextField);
		remove(transmitPortLabel);
		remove(transmitPortTextField);*/
		remove(playerNumberButton);
		add(startGame);
		revalidate();
		repaint();
	}
	
	public void afterQuit() {
		System.exit(0);
	}
	
	public void setShipDirection() {
		if(directionType == ShipDirection.HORIZONTAL) {
			directionType = ShipDirection.VERTICAL; //when we click on this button we change its state
			shipDirectionButton.setText("VERTICAL");
		}
		
		else {
			directionType = ShipDirection.HORIZONTAL; //when we click on this button we change its state
			shipDirectionButton.setText("HORIZONTAL");
			
		}
			
	}
	
	public void addStartListener(ActionListener listenForStartGame) {
		startGame.addActionListener(listenForStartGame);
	}

	public void addQuitListener(ActionListener listenForQuitGame) {
		quitGame.addActionListener(listenForQuitGame);
	}
	
	public void addConnectListener(ActionListener listenForConnection) {
		connect.addActionListener(listenForConnection);
	}
	
	public void addSetShipDirectionListener(ActionListener listenForSetShipDirection) {
		shipDirectionButton.addActionListener(listenForSetShipDirection);
	}
	
	public void addListenPortListener(ActionListener listenForListenPort) {
		listenPortButton.addActionListener(listenForListenPort);
	}
	
	public void addPlayerNumberListener(ActionListener listenForPlayerNumber) {
		playerNumberButton.addActionListener(listenForPlayerNumber);
	}
}
