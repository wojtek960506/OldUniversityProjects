package battleshipMVC;



import battleshipView.*;

import battleshipModel.*;
import battleshipController.*;

/**
 * główna klasa, w której uruchamiamy aplikację
 */
public class MainBattleshipMVC{
	
	public static void main(String[] args) {
	
		BattleshipModel theModel = new BattleshipModel();
		View view = new View();
		
		BattleshipController theController = new BattleshipController(view, theModel);
		
		theController.battleOn();	
		
		System.exit(0);
		
	}
}





/*----------------------------------------------------------------------------------------------
		//theGameView.startGame();
		theModel.setShipPosition(9, 0, ShipDirection.HORIZONTAL);	
		theModel.setShipPosition(9, 6, ShipDirection.HORIZONTAL);
		theModel.setShipPosition(4, 9, ShipDirection.VERTICAL);
		theModel.setShipPosition(4, 0, ShipDirection.VERTICAL);
		theModel.setShipPosition(0, 9, ShipDirection.VERTICAL);
		theModel.setShipPosition(0, 0, ShipDirection.VERTICAL);
		theModel.setShipPosition(0, 2, ShipDirection.HORIZONTAL);
		theModel.setShipPosition(0, 5, ShipDirection.HORIZONTAL);
		theModel.setShipPosition(0, 7, ShipDirection.HORIZONTAL);
		
		
		int mv = 5;
		int nv = 4;
		int mh = 0;
		int nh = 2;
		int i,j;
		
		theModel.setShipPosition(mv, nv, ShipDirection.VERTICAL);
		theModel.setShipPosition(mh,nh,ShipDirection.HORIZONTAL);
		
		
		//vertical
		for( i = mv ; i < mv+5 ; i++) {
			theModel.shoot(i,nv);
		}
		
		//horizontal
		for(j = nh ; j < nh + 6 ; j++) {
			theModel.shoot(mh, j);
		}			
		
		theModel.shoot(5, 0);
		theModel.shoot(1, 0);
		theModel.shoot(2, 0);
		theModel.shoot(3, 0);
		theModel.shoot(4, 0);
		
		for(i = 1 ; i < BattleshipModel.BOARD_SIZE - 1 ; i++ ) {
			for( j = 1 ; j < BattleshipModel.BOARD_SIZE - 1 ; j++) {
				theModel.shoot(i,j);
			}
		}
		
	
		
		//theView.setVisible(true);
----------------------------------------------------------------------------------------------------------*/
		

	
	
	
	
	
