/**
 * Wojciech Zielinski IOP_Project_Hotel
 */

public class Guest {
	private String firstName;
	private String secondName;
	private int guestId;

	//TODO
	public Guest() {
		firstName = null;
		secondName = null;
		guestId = 0;
	}
	public Guest(int guestId, String firstName, String secondName) {
		this.guestId = guestId;
		this.firstName = firstName;
		this.secondName = secondName;
	}
	
	public String getFirstName() {
		return firstName;
	}

	public String getSecondName() {
		return secondName;
	}

	public int getGuestId() {
		return guestId;
	}

	
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public void setSecondName(String secondName) {
		this.secondName = secondName;
	}

	public void setGuestId(int guestId) {
		this.guestId = guestId;
	}

	public void setDetails(int guestId, String firstName, String secondName) {
		setFirstName(firstName);
		setSecondName(secondName);
		setGuestId(guestId);
	}
	public void showDetails() {
		String id = String.format("|%9s  |", guestId);
		String fN = String.format("|%11s  |", firstName);
		String sN = String.format("|%15s  |", secondName);
		System.out.printf("%s%s%s\n", id,fN,sN);
	}
}