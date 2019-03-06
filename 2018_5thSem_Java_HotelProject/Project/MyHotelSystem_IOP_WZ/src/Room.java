/**
 * Wojciech Zielinski IOP_Project_Hotel
 */



public class Room {

	private int roomNumber;
	private RoomStandard roomStandard;
	private float priceForOneNight;
	private int forHowManyBeds;
	private RoomState roomState;

	public Room() {
		roomNumber = 1;
		roomStandard = null;
		priceForOneNight = 0;
		forHowManyBeds = 0;
		roomState = RoomState.EMPTY;
	}
	
	
	
	public int getRoomNumber() {
		return roomNumber;
	}

	public RoomStandard getRoomStandard() {
		return roomStandard;
	}

	public int getForHowManyBeds() {
		return forHowManyBeds;
	}
	
	public RoomState checkState() {
		return roomState;
	}
	
	public float getPriceForOneNight() {
		return priceForOneNight;
	}

	public void setRoomNumber(int roomNumber) {
		this.roomNumber = roomNumber;
	}

	public void setRoomStandard(RoomStandard roomStandard) {
		this.roomStandard = roomStandard;
	}

	public void setForHowManyBeds(int forHowManyBeds) {
		this.forHowManyBeds = forHowManyBeds;
	}
	
	public void setRoomState(RoomState roomState) {
		this.roomState = roomState;
	}
	
	public void setPriceForOneNight (float priceForOneNight) {
		this.priceForOneNight = priceForOneNight;
	}

	public void setDetails(int roomNumber, float priceForOneNight, int forHowManyBeds, RoomState roomState) {
		
		setRoomNumber(roomNumber);
		setPriceForOneNight(priceForOneNight);
		setForHowManyBeds(forHowManyBeds);
		setRoomState(roomState);
	}
	
	public void showDetails() {
		String t = null;
		String num = String.format("|%12s  |", roomNumber);
		String price = String.format("|%17s  |", priceForOneNight);
		String numBeds = String.format("|%10s  |", forHowManyBeds);
		switch(roomState) {
			case EMPTY:
				t = String.format("|%23s  |", "Pusty");
				break;
			case EMPTY_AND_RESERVED:
				t = String.format("|%23s  |", "Pusty i zarezerwowany");
				break;
			case TAKEN:
				t = String.format("|%23s  |", "Zajety");
				break;
			case TAKEN_AND_RESERVED:
				t = String.format("|%23s  |", "Zajety i zarezerwowany");
				break;
		}
		System.out.printf("%s%s%s%s\n", num, price, numBeds, t);
	}
}