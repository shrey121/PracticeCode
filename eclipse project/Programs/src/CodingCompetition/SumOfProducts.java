/**
 * Given a number N, find the 

sum of all products x*y such 

that N/x = y (Integer Division).
Since, the sum can be very 

large, please output this 

modulo 1000000007.
 */

package CodingCompetition;

import java.util.Scanner;

class SumOfProducts {
	public static void

	main(String[] args) {
		Scanner in

		= new Scanner(System.in);
		try {

			int testCases = in.nextInt();

			for (int a = 0; a < testCases; a++) {

				int n = in.nextInt();

				int x, y;

				long sum = 0;

				for (x = 1; x <= n; x++)

				{

					y = n / x;

					sum = sum + (y * x);

				}

				sum = sum % 1000000007;

				System.out.println(sum);
			}
		} catch

		(Exception e) {

			e.printStackTrace();
		} finally {

			in.close();
		}
	}
}
