import java.util.Date;
import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.text.ParseException;
import java.text.ParsePosition;

public class DayOfWeek {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		String pattern = "M d y";
		SimpleDateFormat simpleDate = new SimpleDateFormat(pattern);
		ParsePosition pp = new ParsePosition(0);
		Date date = simpleDate.parse(scan.nextLine(),pp);			
		Calendar c = new GregorianCalendar();
		c.setTime(date);
		System.out.println(c.toString());
	}
}
