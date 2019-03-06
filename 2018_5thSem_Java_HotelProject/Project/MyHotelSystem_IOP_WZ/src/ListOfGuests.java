/**
 * 
 */

import java.util.ArrayList;
import java.util.List;

public class ListOfGuests {
	private int guestId;
	private List<Guest> guests;
	
	public ListOfGuests() {
		guests = new ArrayList<Guest>();
		guestId = 1;
	}

	public List<Guest> getListOfGuests() {
		return guests;
	}
	
	public void showListOfGuests() {
		String id = String.format("| %9s |", "Id goscia");
		String fN = String.format("| %11s |","Imie goscia");
		String sN = String.format("| %15s |","Nazwisko goscia");
		System.out.printf("%s%s%s\n", id,fN,sN);
		
		for (Guest g : guests) {
			g.showDetails();
		}
	}
	
	public void addGuest(String firstName, String secondName) {
		Guest guest = new Guest();
		guest.setDetails(guestId, firstName, secondName);
		guests.add(guest);
		guestId++; //dodalismy goscia, wiec kolejny musi miec inne id
	}
}