import java.util.Random;
import java.util.Scanner;


public class RandomNumberGenerator 
{
	public static void main(String[] args) 
	{
		Random r = new Random();
		Scanner s = new Scanner(System.in);
		System.out.println("give max value: ");
		int maxValue = s.nextInt();
		for(int i=0;i<5;i++)
		{
			System.out.println(Math.abs(r.nextInt() % maxValue));
		}
	}
}
