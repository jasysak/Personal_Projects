package main.java.mypkg;
import java.util.Scanner;

/**
 * A simple change maker. Convert ##.## to number of
 * whole dollars, quarters, dimes, nickels, and pennies
 * based on an item cost and payment amount.
 */

/**
 * @author jsysak
 *
 */
public class ComputeChange {
	public static void main(String[] args) {
		
		final int CONVERT_CENTS = 100;
		final int CONVERT_Q = 25;
		final int CONVERT_D = 10;
		final int CONVERT_N = 5;
		double changeDue;
		int changeDueInt;
		
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the item cost in dollars and cents (##.##): ");
		double itemCost = input.nextDouble();
		System.out.println("Enter the customer payment amount in dollars and cents (##.##): ");
		double paymentAmount = input.nextDouble();
		// (not tested) below 2 lines could be condensed to 
		// changeDue = (paymentAount - itemCost) * CONVERT_CENTS;
		changeDue = paymentAmount - itemCost;
		changeDue *= CONVERT_CENTS;
		changeDueInt = (int)changeDue;
		// changeDueInt = (int)changeDue * CONVERT_CENTS; should be able to replace above 2 lines
		// but it doesn't work! Why?
		System.out.println("The Change due is: ");
		System.out.println(changeDueInt / CONVERT_CENTS + " Dollars");
		System.out.println(changeDueInt % CONVERT_CENTS / CONVERT_Q + " Quarters");
		System.out.println(changeDueInt % CONVERT_CENTS % CONVERT_Q / CONVERT_D + " Dimes");
		System.out.println(changeDueInt % CONVERT_CENTS % CONVERT_Q % CONVERT_D / CONVERT_N + " Nickels");
		System.out.println(changeDueInt % CONVERT_CENTS % CONVERT_Q % CONVERT_D % CONVERT_N + " Pennies");
		// The above series of divide & remainder operations works for low values, like 5.51 & 10, but 
		// does not correctly calculate for higher values like 95.51/100. Why?
		// Also note that changeDueInt could be replaced with (int)changeDue in each case, results are the
		// same either way.
		input.close();
		
	}

}
