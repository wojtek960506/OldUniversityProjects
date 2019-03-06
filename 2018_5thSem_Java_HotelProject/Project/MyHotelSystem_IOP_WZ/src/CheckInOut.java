/**
 * Wojciech Zielinski IOP_Project_Hotel
 */

import java.text.SimpleDateFormat;
import java.util.Date;


public class CheckInOut {
	
	private int checkInOutId;
	private Date checkInDate;
	private Date checkOutDate;
	private float price;
	private Guest guest;
	private Room room;
	
	//TODO
	public CheckInOut() {
		checkInOutId = 0;
		checkInDate = null;
		checkOutDate = null;
		price = 0;
		guest = null;
		room = null;
	}
	
	public void showDetails() {
		SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");
		
		String tempCheckInDate = dateFormat.format(checkInDate);
		String tempCheckOutDate = dateFormat.format(checkOutDate);
		
		String id = String.format("|%9s  |", checkInOutId);
		String fN = String.format("|%11s  |", guest.getFirstName());
		String sN = String.format("|%15s  |", guest.getSecondName());
		String rN = String.format("|%12s  |", room.getRoomNumber());
		String bD = String.format("|%15s  |", tempCheckInDate);
		String eD = String.format("|%13s  |", tempCheckOutDate);
		String p = String.format("|%10s     |", price);
		
		System.out.printf("%s%s%s%s%s%s%s\n", id,fN,sN, rN, bD, eD, p);
	}
	
	public void setDetails(	int checkInOutId, Guest guest, Room room,
		Date checkInDate, Date checkOutDate, float price) {
		setCheckInOutId(checkInOutId);
		setGuest(guest);
		setRoom(room);
		setCheckInDate(checkInDate);
		setCheckOutDate(checkOutDate);
		setPrice(price);
	}
	
	public int getCheckInOutId() {
		return checkInOutId;
	}
	
	public Date getCheckInDate() {
		return checkInDate;
	}

	public Date getCheckOutDate() {
		return checkOutDate;
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

	public void setCheckInOutId(int checkInOutId) {
		this.checkInOutId = checkInOutId;
	}
	
	public void setCheckInDate(Date checkInDate) {
		this.checkInDate = checkInDate;
	}
	
	public void setCheckOutDate(Date checkOutDate) {
		this.checkOutDate = checkOutDate;
	}
	
	public void setGuest (Guest guest) {
		this.guest = guest;
	}
	
	public void setRoom (Room room) {
		this.room = room;
	}
	
	public void setPrice (float price) {
		this.price = price;
	}
}