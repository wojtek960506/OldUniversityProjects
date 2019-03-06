import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Date;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public class ConsoleView {
	Scanner keyboard;
	BufferedReader reader;
	
	public ConsoleView() {
		keyboard = new Scanner(System.in);
		reader = new BufferedReader(new InputStreamReader(System.in));
	}
	
	public void showMainMenu() {
		System.out.println("Wybierz numer operacji, ktora chcesz wykonac.");
		System.out.println("1 -> wyswietl liste gosci");
		System.out.println("2 -> wyswietl liste pokoi");
		System.out.println("3 -> wyswietl liste rezerwacji");
		System.out.println("4 -> wyswietl liste pobytow");
		System.out.println("5 -> zamknij program");
	}
	
	public void addGuest(Application app) {
		System.out.println("CZY CHCESZ DODAC GOSCIA ?");
		System.out.println("Wybierz numer opcji:");
		System.out.println("1 -> TAK ; 2 -> NIE");
		if((chooseOperation(1,2)) == 2) {
			return;
		}
		 try {
			String firstName;
			String secondName;
			System.out.println("Podaj imie goscia.");
			firstName = reader.readLine();
			System.out.println("Podaj nazwisko goscia.");
			secondName = reader.readLine();
			app.addGuest(firstName, secondName);
		 } catch (IOException e) {
			 System.out.println("Blad w AddGuest: " + e);
		 }
	}
	
	public void addRoom(Application app) {
		System.out.println("CZY CHCESZ DODAC POKOJ ?");
		System.out.println("Wybierz numer opcji:");
		System.out.println("1 -> TAK ; 2 -> NIE");
		if((chooseOperation(1,2)) == 2) {
			return;
		}
		 try {
			float priceForOneNight;
			int forHowManyBeds;
			System.out.println("Podaj cene za jedna noc.");
			priceForOneNight = keyboard.nextFloat();
			System.out.println("Podaj iluosobowy jest to pokoj.");
			forHowManyBeds = keyboard.nextInt();
			app.addRoom(priceForOneNight, forHowManyBeds);
		 } catch (InputMismatchException e) {
			 System.out.println("Blad w addRoom: " + e);
		 }
	}
	
	public void addReservation(Application app) {
		System.out.println("CZY CHCESZ DODAC REZERWACJE ?");
		System.out.println("Wybierz numer opcji:");
		System.out.println("1 -> TAK ; 2 -> NIE");
		if((chooseOperation(1,2)) == 2) {
			return;
		}
		try {
			int guestId;
			int roomNum;
			String beginDate;
			String endDate;
			
			int bGSize = app.getListOfGuests().size();
			int bRSize = app.getHotel().size();
			
			if( !(app.getListOfGuests().size() == 0) )
				System.out.println("\nWybierz goscia z listy gosci.");
			app.showListOfGuests(false);
			
			if(app.getListOfGuests().size() == 0) {
				System.out.println("NIE DODANO GOSCIA WIEC NADAL NIE MA GOSCI W TYM HOTELU. NIE MOZNA DOKONAC REZERWACJI. SPROBUJ PONOWNIE.");
				return;
			}
			if(bGSize!=0) {
				System.out.println("Wpisz id wybranego goscia.");
				guestId = chooseId(app,1);
			}
			else
				guestId = app.getListOfGuests().get(0).getGuestId();
				
			if( !(app.getHotel().size() == 0) )
				System.out.println("\nWybierz pokoj z listy pokoi.");
			app.showListOfRooms(false);
			
			if(app.getHotel().size() == 0) {
				System.out.println("NIE DODANO POKOJU WIEC NADAL NIE MA POKOI W TYM HOTELU. NIE MOZNA DOKONAC REZERWACJI. SPROBUJ PONOWNIE.");
				return;
			}
			
			if(bRSize!=0) {
				System.out.println("Wpisz numer wybranego pokoju.");
				roomNum = chooseId(app,2);
			}
			else
				roomNum = app.getHotel().get(0).getRoomNumber();
			
			System.out.println("Wpisz date poczatku rezerwacji. (format -> [dd-mm-yyyy])");
			beginDate = reader.readLine();
			
			System.out.println("Wpisz date konca rezerwacji. (format -> [dd-mm-yyyy])");
			endDate = reader.readLine();
			
			Date bD = new SimpleDateFormat("dd-MM-yyyy").parse(beginDate);
			Date eD = new SimpleDateFormat("dd-MM-yyyy").parse(endDate);
			
			Room room = new Room();
			for(Room r : app.getHotel()) {
				if(r.getRoomNumber() == roomNum) {
					r.setRoomState(RoomState.EMPTY_AND_RESERVED);
					room = r;
					break;
				}
			}
			
			Guest guest = new Guest();
			for(Guest g : app.getListOfGuests()) {
				if(g.getGuestId() == guestId) {
					guest = g;
					break;
				}
			}
			
			
			float price = (int)( (eD.getTime() - bD.getTime()) / (1000 * 60 * 60 * 24)) * room.getPriceForOneNight();
			
			app.addReservation(guest, room, bD, eD, price);
			
		 } catch (InputMismatchException | IOException e) {
			 System.out.println("Blad w addReservation: " + e);
		 } catch (ParseException e) {
			e.printStackTrace();
		}
		
	}
	
	public void addCheckInOut(Application app) {
		System.out.println("CZY CHCESZ DODAC POBYT ?");
		System.out.println("Wybierz numer opcji:");
		System.out.println("1 -> TAK ; 2 -> NIE");
		if((chooseOperation(1,2)) == 2) {
			return;
		}
		System.out.println("WYBIERZ OPCJE DODAWANIA POBYTU.");
		System.out.println("1 -> Na podstawie rezerwacji.");
		System.out.println("2 -> Bez rezerwacji.");
		int num = chooseOperation(1,2);
		if(num == 1) { //wybieramy rezerwacje z listy
			try {
				int reservationId;
				Guest guest = null;
				Room room = null;
				Date checkInDate = null;
				Date checkOutDate = null;
				float price = 0;
				
				if( (app.getListOfReservations().size() == 0) ) {
					System.out.println("\nNIE MA REZERWACJI W TYM HOTELU.");
					return;
				}
				app.showListOfReservations(false);
				
				System.out.println("Wpisz id wybranej rezerwacji.");
				reservationId = chooseId(app,3);
				int flag = 0;
				//Reservation reservation = new Reservation();
				for(Reservation r : app.getListOfReservations()) {
					if(r.getReservationId() == reservationId) {
						guest = r.getGuest();
						room = r.getRoom();
						checkInDate = r.getBeginDate();
						checkOutDate = r.getEndDate();
						price = r.getPrice();
						
						app.getListOfReservations().remove(r); //usuwamy rezerwacje
						
						for(Reservation res : app.getListOfReservations()) {
							if(res.getRoom().getRoomNumber() == room.getRoomNumber()) { //sprawdzamy jak zmienic stan pokoju
								//r.getRoom().setRoomState(RoomState.TAKEN_AND_RESERVED);
								//room = r.getRoom();
								room.setRoomState(RoomState.TAKEN_AND_RESERVED);
								flag = 1;
								break;
							}
						}
						if(flag == 0) { //sprawdzamy czy juz nie zmienilismy stanu
							room.setRoomState(RoomState.TAKEN);
						}
						
						break;
					}
				} 
				
				
				app.addCheckInOut(guest, room, checkInDate, checkOutDate, price);
			} catch (InputMismatchException e) {
				System.out.println("Blad w addChechInOut: " + e);
			}
		}
		if(num == 2) {
			try {
				int guestId;
				int roomNum;
				String beginDate;
				String endDate;
				
				int bGSize = app.getListOfGuests().size();
				int bRSize = app.getHotel().size();
				
				if( !(app.getListOfGuests().size() == 0) )
					System.out.println("\nWybierz goscia z listy gosci.");
				app.showListOfGuests(false);
				
				if(app.getListOfGuests().size() == 0) {
					System.out.println("NIE DODANO GOSCIA WIEC NADAL NIE MA GOSCI W TYM HOTELU. NIE MOZNA DOKONAC REZERWACJI. SPROBUJ PONOWNIE.");
					return;
				}
				
				if(bGSize!=0) {
					System.out.println("Wpisz id wybranego goscia.");
					guestId = chooseId(app,1);
				}
				else
					guestId = app.getListOfGuests().get(0).getGuestId();
				
				//System.out.println("Wpisz id wybranego goscia.");
				//guestId = chooseId(app,1);
				
				if( !(app.getHotel().size() == 0) )
					System.out.println("\nWybierz pokoj z listy pokoi.");
				app.showListOfRooms(false);
				
				if(app.getHotel().size() == 0) {
					System.out.println("NIE DODANO POKOJU WIEC NADAL NIE MA POKOI W TYM HOTELU. NIE MOZNA DOKONAC REZERWACJI. SPROBUJ PONOWNIE.");
					return;
				}
				
				if(bRSize!=0) {
					System.out.println("Wpisz numer wybranego pokoju.");
					roomNum = chooseId(app,2);
				}
				else
					roomNum = app.getHotel().get(0).getRoomNumber();
				
				//System.out.println("Wpisz numer wybranego pokoju.");
				//roomNum = chooseId(app,2);
				
				System.out.println("Wpisz date poczatku pobytu. (format -> [dd-mm-yyyy])");
				beginDate = reader.readLine();
				
				System.out.println("Wpisz date konca pobytu. (format -> [dd-mm-yyyy])");
				endDate = reader.readLine();
				
				Date bD = new SimpleDateFormat("dd-MM-yyyy").parse(beginDate);
				Date eD = new SimpleDateFormat("dd-MM-yyyy").parse(endDate);
				//szukamy pokoju na podstawie numeru
				Room room = new Room();
				for(Room r : app.getHotel()) {
					if(r.getRoomNumber() == roomNum) {
						int flag = 0;
						for(Reservation res : app.getListOfReservations()) {
							if(res.getRoom().getRoomNumber() == roomNum) { //sprawdzamy jak zmienic stan pokoju
								r.setRoomState(RoomState.TAKEN_AND_RESERVED);
								room = r;
								flag = 1;
								break;
							}
						}
						if(flag == 0) { //sprawdzamy czy juz nie zmienilismy stanu
							r.setRoomState(RoomState.TAKEN);
							room = r;
						}
						break;
					}
				}
				//szukamy goscia na podstawie id
				Guest guest = new Guest();
				for(Guest g : app.getListOfGuests()) {
					if(g.getGuestId() == guestId) {
						guest = g;
						break;
					}
				}
		
				float price = (int)( (eD.getTime() - bD.getTime()) / (1000 * 60 * 60 * 24)) * room.getPriceForOneNight();
				
				app.addCheckInOut(guest, room, bD, eD, price);
				
			 } catch (InputMismatchException | IOException e) {
				 System.out.println("Blad w addCheckInOut: " + e);
			 } catch (ParseException e) {
				e.printStackTrace();
			}
		}
	}
	
	public int chooseId(Application app, int flag) {
		int id;
		List<Integer> tempList = new ArrayList<Integer>();
		if(flag == 1) {
			for(Guest g : app.getListOfGuests()) {
				tempList.add(g.getGuestId());
			}
		}
		if(flag == 2) {
			for(Room r: app.getHotel()) {
				tempList.add(r.getRoomNumber());
			}
		}
		if(flag == 3) {
			for(Reservation r : app.getListOfReservations()) {
				tempList.add(r.getReservationId());
			}
		}
		
		
		while(true) {
			try {
				id = keyboard.nextInt();
				while( !tempList.contains(id) ) {
					switch(flag) {
						case 1:
							System.out.println("Mozesz wybrac tylko id istniejacego goscia. Podaj ponownie.");
							break;
						case 2:
							System.out.println("Mozesz wybrac tylko numer istniejacego pokoju. Podaj ponownie.");
							break;
						case 3:
							System.out.println("Mozesz wybrac tylko id istniejacej rezerwacji. Podaj ponownie.");
							break;
					}
					
					//if(flag == 1)
						//System.out.println("Mozesz wybrac tylko id istniejacego goscia. Podaj ponownie.");
					//if(flag == 2)
						//System.out.println("Mozesz wybrac tylko numer istniejacego pokoju. Podaj ponownie.");
					id = keyboard.nextInt();
				}
				break;
			} catch(InputMismatchException e) {
				System.out.println("Numer operacji to liczba naturalna. Podaj ponownie.");
				keyboard.nextLine();
			}
		}
		
		return id;
	}
	
	public int chooseOperation(int begin, int end) {
		int num;
		while(true) {
			try {
				while( (num = keyboard.nextInt()) > end || num < begin ) {
					System.out.println("Numer operacji to liczba od " + begin + " do " + end + ". Podaj ponownie.");
				}
				break;
			} catch(InputMismatchException e) {
				System.out.println("Numer operacji to liczba naturalna. Podaj ponownie.");
				keyboard.nextLine();
			}
		}
		return num;
	}
}
