//MyDate.java
import java.util.*;
import java.io.*;

public class MyDate {
    public static void main( String [] args ) {
        int year  = 0;
        int month = 0;
        int day   = 0;
       
        Calendar cal = Calendar.getInstance();
       
        try {
            InputStreamReader fr = new InputStreamReader(System.in);
            BufferedReader    br = new BufferedReader(fr);
            
            System.out.println("Input year");
            year  = Integer.valueOf(br.readLine()).intValue(); 

            System.out.println("Input month");
            month = Integer.valueOf(br.readLine()).intValue(); 

            System.out.println("Input day");
            day   = Integer.valueOf(br.readLine()).intValue(); 
        }
        catch(Exception e) {
            System.out.println(e);
        }

        cal.set( year, month-1, day );
        int dayOfYear = cal.get(Calendar.DAY_OF_YEAR);
        int thisYear  = cal.get(Calendar.YEAR);
        int thisMonth = cal.get(Calendar.MONTH)+1;
        int thisDay   = cal.get(Calendar.DATE);

        System.out.println("Today is Year:"+ thisYear + " Month:"+ thisMonth +" Day:"+ thisDay);
        System.out.println("Today is "+ dayOfYear +"Day of Year"+ thisYear);
        
        switch( cal.get(Calendar.DAY_OF_WEEK) ) {
        case 1: System.out.println("Sunday");  
            break;
        case 2: System.out.println("Monday");  
            break;
        case 3: System.out.println("Tuesday");   
            break;
        case 4: System.out.println("Wednesday"); 
            break;
        case 5: System.out.println("Thursday");  
            break;
        case 6: System.out.println("Friday");    
            break;
        case 7: System.out.println("Satday");   
            break;
        }
    }
}