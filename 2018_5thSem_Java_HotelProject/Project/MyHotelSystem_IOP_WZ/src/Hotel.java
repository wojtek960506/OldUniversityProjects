import java.util.ArrayList;
import java.util.List;

/**
 * Wojciech Zielinski IOP_Project_Hotel
 */


public class Hotel {
	
	//w sumie to chyba nie potrzebne bo to jest ukryte w rozmiarze listy
	//private int numberOfRooms;
	
	private List<Room> rooms;
	int roomId;

	public Hotel() {
		rooms = new ArrayList<Room>();
		roomId = 1;
	}
	
	
	public List<Room> getListOfRooms() {
		return rooms;
	}
	
	public void showListOfRooms() {
		if(rooms.size() == 0) {
			System.out.println("Nie ma pokoi w tym hotelu.");
			return;
		}
		
		String num = String.format("| %12s |", "Numer pokoju");
		String price = String.format("| %17s |", "Cena za jedna noc");
		String numBeds = String.format("| %10s |", "Iluosobowy");
		String t = String.format("| %23s |", "Stan pokoju");
		System.out.printf("%s%s%s%s\n", num, price, numBeds, t);
		
		for (Room r  : rooms) {
			r.showDetails();
		}
	}
	
	public void addRoom(float priceForOneNight, int forHowManyBeds) {
		Room room = new Room();
		room.setDetails(roomId, priceForOneNight, forHowManyBeds, RoomState.EMPTY);
		rooms.add(room);
		roomId++;
	}
	//potem sie zastanowie czy napisac te funkcje jak juz bede pisal aplikacje
	public void getRoomDetails() {
		//TODO
	}
	
	public void ifExists() {
		//TODO
	}
	
	/*nie musimy modyfikowac ani usuwac
	public void modifyRoom() {
		
	}
	public void deleteRoom() {
		
	}*/

}