/**
 * Wojciech Zielinski IOP_Project_Hotel
 */

import java.io.IOException;
import java.util.Date;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Application extends Exception{
	private Hotel hotel;
	private ListOfGuests listOfGuests;
	private ConsoleView consoleView;
	private ListOfReservations listOfReservations;
	private ListOfCheckInOuts listOfCheckInOuts;
	
	public Application() {
		hotel = new Hotel();
		listOfGuests = new ListOfGuests();
		listOfReservations = new ListOfReservations();
		listOfCheckInOuts = new ListOfCheckInOuts();
		consoleView = new ConsoleView();
		
	}
	
	public void run() {
		int num;
		consoleView.showMainMenu();
		while((num = consoleView.chooseOperation(1,5)) != 5) {
			switch(num) {
				case 1:
					showListOfGuests(true);
					break;
				case 2:
					showListOfRooms(true);
					break;
				case 3:
					showListOfReservations(true);
					break;
				case 4:
					showListOfCheckInOuts();
					break;
			}
			consoleView.showMainMenu();
		}
		System.out.println("KONIEC PROGRAMU");
	}
	
	public void showListOfGuests(boolean b) {
		if(listOfGuests.getListOfGuests().size() == 0) {
			if(b)
				System.out.println("Nie ma gosci w tym hotelu.");
			else
				System.out.println("Nie ma gosci w tym hotelu. Wprowadz dane goscia dla ktorego chcesz dokonac rezerwacji.");
			consoleView.addGuest(this);
			return;
		}
		else {
			listOfGuests.showListOfGuests();
		}
		if(b)
			consoleView.addGuest(this);
	}
	
	public void showListOfRooms(boolean b) {
		if(hotel.getListOfRooms().size() == 0) {
			if(b)
				System.out.println("Nie ma pokoi w tym hotelu.");
			else
				System.out.println("Nie ma pokoi w tym hotelu. Wprowadz dane pokoju ktory gosc chce zarezerwowac.");
			consoleView.addRoom(this);
			return;
		}
		else {
			hotel.showListOfRooms();
		}
		if(b)
			consoleView.addRoom(this);
		
	}
	
	public void showListOfReservations(boolean b) {
		
		listOfReservations.showListOfReservations();
		if(b)
			consoleView.addReservation(this);
	}
	
	public void showListOfCheckInOuts() {
		listOfCheckInOuts.showListOfCheckInOuts();
		consoleView.addCheckInOut(this);
	}
	
	public void addRoom(float priceForOneNight, int forHowManyBeds) {
		hotel.addRoom(priceForOneNight, forHowManyBeds);
	}
	
	public void addGuest(String firstName, String secondName) {
		listOfGuests.addGuest(firstName, secondName);
	}
	
	public void addReservation(Guest guest, Room room, Date beginDate, Date endDate, float price) {
		listOfReservations.addReservation(guest,room,beginDate,endDate,price);
	}

	public void addCheckInOut(Guest guest, Room room, Date beginDate, Date endDate, float price) {
		listOfCheckInOuts.addCheckInOut(guest, room, beginDate, endDate, price);
	}
	
	public List<Guest> getListOfGuests() {
		return listOfGuests.getListOfGuests();
	}
	
	public List<Room> getHotel() {
		return hotel.getListOfRooms();
	}
	
	public List<Reservation> getListOfReservations() {
		return listOfReservations.getListOfReservations();
	}
}