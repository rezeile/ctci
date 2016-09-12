import java.util.Scanner;
import java.text.DecimalFormat;
import java.math.RoundingMode;

public class Echo {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		double d = scan.nextDouble();
		
		DecimalFormat df = new DecimalFormat("sss.###");
		df.setRoundingMode(RoundingMode.HALF_UP);
		
		System.out.println(df.format(d));
	}	
}


