package bdlab;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.List;

public class DBTest {
	public static class Tourists {
		private int touristId;
		private String firstName;
		private String lastName;
		private String countryName;

		public Tourists(int touristId, String firstName, String lastName, String countryName) {
			super();
			this.touristId = touristId;
			this.firstName = firstName;
			this.lastName = lastName;
			this.countryName = countryName;
		}
		
		public Tourists() {}
		
		public int getTouristId() {
			return touristId;
		}

		public void setId(int touristId) {
			this.touristId = touristId;
		}

		public String getFirstName() {
			return firstName;
		}

		public void setFirstName(String firstName) {
			this.firstName = firstName;
		}

		public String getLastName() {
			return lastName;
		}

		public void setLastName(String lastName) {
			this.lastName = lastName;
		}

		public String getCountryName() {
			return countryName;
		}

		public void setCountryName(String countryName) {
			this.countryName = countryName;
		}

		public String toString() {
			return String.format("Tourists(%d, %s, %s, %s)", touristId, firstName, lastName, countryName); 
		}
	}

	public final static ResultSetToBean<Tourists> touristsConverter = new ResultSetToBean<Tourists>() {
		public Tourists convert(ResultSet rs) throws Exception {
			Tourists e = new Tourists();
			e.setId(rs.getInt("TOURIST_ID"));
			e.setFirstName(rs.getString("TOURIST_FIRST_NAME"));
			e.setLastName(rs.getString("TOURIST_LAST_NAME"));
			e.setCountryName(rs.getString("TOURIST_COUNTRY"));
			return e;
		}
	};

	public static ResultSetToBean<Tourists> getTouristconverter() {
		return touristsConverter;
	}

	public static void main(String[] args) {
	
	//***************************************************************************************************************************************//
	//***************************************************************************************************************************************//		
		//update
		boolean result = DBManager.run(new Task<Boolean>() {
			public Boolean execute(PreparedStatement ps) throws Exception {
					
				ps.setString(1, "Piotr");
				ps.setString(2, "Walaszek");
				ps.setString(3, "Poland");
				ps.setInt(4, 500);
	
				return ps.executeUpdate() > 0;
			}
		}, "UPDATE tourists SET tourist_first_name = ?, tourist_last_name = ?, tourist_country = ? WHERE tourist_id = ?");
				
		System.out.println();
		System.out.println(result ? "UPDATE. Udalo sie" : "UPDATE. Nie udalo sie");
		
		//post update select
		List<Tourists> Tourists = DBManager.run(new Query() {
			public void prepareQuery(PreparedStatement ps) throws Exception {
					ps.setInt(1, 500);
			}
		}, touristsConverter, "SELECT * FROM tourists WHERE tourist_id = ?");
	
		System.out.println("Post update query results: ");
		for (Tourists e: Tourists) {
			System.out.println(e);
			System.out.println();
		}
	
	//***************************************************************************************************************************************//
	//***************************************************************************************************************************************//		
		//delete
		result = DBManager.run(new Task<Boolean>() {
			public Boolean execute(PreparedStatement ps) throws Exception {	
				ps.setInt(1, 999);
	
				return ps.executeUpdate() > 0;
			}
		}, "DELETE FROM tourists WHERE tourist_id = ?");
		System.out.println();
		System.out.println(result ? "DELETE. Udalo sie" : "DELETE. Nie udalo sie");
		
		//post delete select
		Tourists = DBManager.run(new Query() {
			public void prepareQuery(PreparedStatement ps) throws Exception {
					ps.setInt(1, 999);
			}
		}, touristsConverter, "SELECT * FROM tourists WHERE tourist_id = ?");
		
		System.out.println("Post delete query results: ");
		for (Tourists e: Tourists) {
			System.out.println(e);
			System.out.println();
		}

	//***************************************************************************************************************************************//
	//***************************************************************************************************************************************//
		//insert
		result = DBManager.run(new Task<Boolean>() {
		public Boolean execute(PreparedStatement ps) throws Exception {
				
			ps.setInt(1, 1);
			ps.setString(2, "Iker");
			ps.setString(3, "Casillas");
			ps.setString(4, "Spain");
				
			return ps.executeUpdate() > 0;
			}
		}, "INSERT INTO tourists(tourist_id, tourist_first_name, tourist_last_name, tourist_country) VALUES (?, ?, ?, ?)");
		
		System.out.println();
		System.out.println(result ? "INSERT. Udalo sie" : "INSERT. Nie udalo sie");

		//post insert select
		Tourists = DBManager.run(new Query() {
			public void prepareQuery(PreparedStatement ps) throws Exception {
				ps.setString(1, "Iker");
				ps.setString(2, "Casillas");
				ps.setString(3, "Spain");
			}
		}, touristsConverter, "SELECT * FROM tourists WHERE tourist_first_name = ? AND tourist_last_name = ? AND tourist_country = ?");
		
		System.out.println("Post insert query results: ");
		for (Tourists e: Tourists) {
			System.out.println(e);
			System.out.println();
		}
	}

}
