package touristParser;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TouristNameParser {
	
	private static final String FILENAME1 = "D:\\Moje_dokumenty\\EiTI_PW\\sem4\\PROZ\\Java_Workspace\\TouristNameParser\\file_w.txt";
	private static final String FILENAME = "D:\\Moje_dokumenty\\EiTI_PW\\sem4\\PROZ\\Java_Workspace\\TouristNameParser\\filename_w.txt";
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<String> list = new ArrayList<String>();
		File file = new File(FILENAME1);
		BufferedReader reader = null;

		try {
		    reader = new BufferedReader(new FileReader(file));
		    String text = null;

		    while ((text = reader.readLine()) != null) {
		        if((int)(text.charAt(0))-48 < 10 && (int)(text.charAt(0))-48 > -1)
		        	continue;
		    	//if(Integer.parseInt(text) < 100)
		        	//continue;
		    	list.add(text);
		    }
		} catch (FileNotFoundException e) {
		    e.printStackTrace();
		} catch (IOException e) {
		    e.printStackTrace();
		} finally {
		    try {
		        if (reader != null) {
		            reader.close();
		        }
		    } catch (IOException e) {
		    }
		}

		//print out the list
		//System.out.println(list.get(0));
		//System.out.println(list.get(1));
		
		BufferedWriter bw = null;
		FileWriter fw = null;

		try {

			

			fw = new FileWriter(FILENAME);
			bw = new BufferedWriter(fw);
			//bw.write(content);
			
			int i=0;
			for (String temp : list) {
				bw.write("\'");
				bw.write(temp);
				bw.write("\'");
				bw.write(", ");
				i++;
			}

			System.out.println("Done. " + i );

		} catch (IOException e) {

			e.printStackTrace();

		} finally {

			try {

				if (bw != null)
					bw.close();

				if (fw != null)
					fw.close();

			} catch (IOException ex) {

				ex.printStackTrace();

			}

		}

		
	}

}
