import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Wojciech Zielinski IOP_Project_Hotel
 */

public class ListOfReservations {
	
	private List<Reservation> reservations;
	int reservationId;
	
	public ListOfReservations() {
		reservations = new ArrayList<Reservation>();
		reservationId = 1;
	}

	public List<Reservation> getListOfReservations() {
		return reservations;
	}
	
	public void showListOfReservations() {
		if(reservations.size() == 0) {
			System.out.println("Nie ma rezerwacji w tym hotelu");
			return;
		}
		
		String id = String.format("| %13s |", "Id rezerwacji");
		String fN = String.format("| %11s |","Imie goscia");
		String sN = String.format("| %15s |","Nazwisko goscia");
		String rN = String.format("| %12s |","Numer pokoju");
		String bD = String.format("| %19s |","Poczatek rezerwacji");
		String eD = String.format("| %17s |","Koniec rezerwacji");
		String p = String.format("| %28s |","Cena za zarezerwowany pobyt");
		
		System.out.printf("%s%s%s%s%s%s%s\n", id,fN,sN, rN, bD, eD, p);
		for (Reservation r : reservations) {
			r.showDetails();
		}
	}
	
	public void addReservation(Guest guest, Room room, Date beginDate, Date endDate, float price) {
		Reservation reservation = new Reservation();
		reservation.setDetails(reservationId, guest, room, beginDate, endDate, price);
		reservations.add(reservation);
		reservationId++;
	}
	
	//potem sie zastanowie czy napisac te funkcje jak juz bede pisal aplikacje
	public void getReservationDetails() {
		//TODO
	}

	public void ifExists() {
		//TODO
	}
	
	/*nie musze modyfikowac ani usuwac
	public void modifyReservation() {
		
	}
	public void deleteReservation() {
	
	}*/
}