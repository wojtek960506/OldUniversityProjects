/**
 * Wojciech Zielinski IOP_Project_Hotel
 */

import java.util.Date;
import java.text.SimpleDateFormat;

public class Reservation {
	
	private int reservationId;
	private Date beginDate;
	private Date endDate;
	private float price;
	private Room room;
	private Guest guest;

	public Reservation() {
		reservationId = 0;
		beginDate = null;
		endDate = null;
		price = 0;
		room = null;
		guest = null;		
	}

	public int getReservationId() {
		return reservationId; 
	}

	public Date getBeginDate() {
		return beginDate;
	}

	public Date getEndDate() {
		return endDate;
	}
	
	public Guest getGuest() {
		return guest;
	}

	public Room getRoom() {
		return room;
	}

	public float getPrice() {
		return price;
	}
	
	public void setReservationId(int reservationId) {
		this.reservationId = reservationId;
	}

	public void setBeginDate(Date beginDate) {
		this.beginDate = beginDate;
	}

	
	public void setEndDate(Date endDate) {
		this.endDate = endDate;
	}

	public void setGuest(Guest guest) {
		this.guest = guest;
	}
	
	public void setRoom(Room room) {
		this.room = room;
	}
	
	public void setPrice(float price) {
		this.price = price;
	}

	public void setDetails(	int reservationId, Guest guest, Room room,
							Date beginDate, Date endDate, float price) {
		setReservationId(reservationId);
		setGuest(guest);
		setRoom(room);
		setBeginDate(beginDate);
		setEndDate(endDate);
		setPrice(price);
	}
	
	public void showDetails() {
		SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");
		
		String tempBeginDate = dateFormat.format(beginDate);
		String tempEndDate = dateFormat.format(endDate);
		
		String id = String.format("|%13s  |", reservationId);
		String fN = String.format("|%11s  |", guest.getFirstName());
		String sN = String.format("|%15s  |", guest.getSecondName());
		String rN = String.format("|%12s  |", room.getRoomNumber());
		String bD = String.format("|%19s  |", tempBeginDate);
		String eD = String.format("|%17s  |", tempEndDate);
		String p = String.format("|%25s     |", price);
		
		System.out.printf("%s%s%s%s%s%s%s\n", id,fN,sN, rN, bD, eD, p);
	}
}