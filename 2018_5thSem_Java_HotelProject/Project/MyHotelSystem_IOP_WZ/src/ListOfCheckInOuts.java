import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Wojciech Zielinski IOP_Project_Hotel
 */

public class ListOfCheckInOuts{
	private List<CheckInOut> checkInOuts;
	private int checkInOutId;

	public ListOfCheckInOuts() {
		checkInOuts = new ArrayList<CheckInOut>();
		checkInOutId = 1;
	}
	
	public void showListOfCheckInOuts() {
		if(checkInOuts.size() == 0) {
			System.out.println("Nie ma pobytow w tym hotelu.");
			return;
		}
		
		String id = String.format("| %9s |", "Id pobytu");
		String fN = String.format("| %11s |","Imie goscia");
		String sN = String.format("| %15s |","Nazwisko goscia");
		String rN = String.format("| %12s |","Numer pokoju");
		String bD = String.format("| %15s |","Poczatek pobytu");
		String eD = String.format("| %13s |","Koniec pobytu");
		String p = String.format("| %13s |","Cena za pobyt");
		
		System.out.printf("%s%s%s%s%s%s%s\n", id,fN,sN, rN, bD, eD, p);
		for (CheckInOut c : checkInOuts) {
			c.showDetails();
		}
	}
	
	public void addCheckInOut(Guest guest, Room room, Date beginDate, Date endDate, float price) {
		CheckInOut checkInOut = new CheckInOut();
		checkInOut.setDetails(checkInOutId, guest, room, beginDate, endDate, price);
		checkInOuts.add(checkInOut);
		checkInOutId++;
	}
}