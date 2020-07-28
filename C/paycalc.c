/*  paycalc.c -- a simple C program
    that calculates weekly gross pay,
    taxes, and net pay using the user
    input hours worked for the week.
    Tax rate will be varied percentages
    with 3 levels (tiers). See comments
    below.
    
    by Jason A. Sysak 10/23/18
    for COP 1220
*/

#include <stdio.h>

#define PAY_RATE 14.0       // $14.00 / hour
#define STD_WEEK 40.0       // standard work week, 40 hours
#define OVERTIME_RATE 1.5   // time and a half
#define TAX_RATE_T1 0.18    // 18% tax rate tier 1 - first $300
#define CUTOFF_T1 300.00    // cutoff for T1 tax rate
#define TAX_RATE_T2 0.20    // 20% tax rate tier 2 - next $150
#define CUTOFF_T2 150.00    // cutoff for T2 tax rate
#define TAX_RATE_T3 0.23    // 23% tax rate tier 3 - any remaining (>$450)
#define CUTOFF_T3 450.00    // cutoff for T3 tax rate

int main(void) {    

    double hoursWorked = 0;
    double grossPay = 0;
    double totalTax = 0;
    double netPay = 0;    

// User input
    printf("\nA simple gross pay, taxes, and net pay calculator.\n");
    printf("\nEnter the hours worked for the week: ");
    if (scanf("%lf", &hoursWorked)) {
        
        // calc for standard PAY_RATE for worked <= STD_WEEK
        if (hoursWorked <= STD_WEEK) grossPay = hoursWorked * PAY_RATE;
        // add overtime rate (1.5) for any hours in excess of STD_WEEK
        else if (hoursWorked > STD_WEEK) grossPay = (STD_WEEK * PAY_RATE) + ((hoursWorked - STD_WEEK) * (PAY_RATE * OVERTIME_RATE));
    }
// Calculation of taxes and net pay
    
    // base tax rate 18% for first 300, or less
    if ( grossPay <= CUTOFF_T1 )                    
        totalTax = grossPay * TAX_RATE_T1;
    // base tax rate 18% for first 300, 20% for any amount from 300-450 (excluding first 300)
    else if ((grossPay > CUTOFF_T1) && (grossPay <= (CUTOFF_T1 + CUTOFF_T2)))   
        totalTax = ((CUTOFF_T1 * TAX_RATE_T1) + ((grossPay - CUTOFF_T1) * TAX_RATE_T2));
    // base tax rate 18% for first 300, 20% for any amount from 300-450 (excluding first 300), 23% for any amount above 450.
    else 
        totalTax = (CUTOFF_T1 * TAX_RATE_T1) + (CUTOFF_T2 * TAX_RATE_T2) + ((grossPay - (CUTOFF_T1 + CUTOFF_T2)) * TAX_RATE_T3);
    
    netPay = grossPay - totalTax;

// Final output
   
    printf("\nGross Pay: $%.2lf", grossPay);
    printf("\nTotal Tax: $%.2lf", totalTax);
    printf("\nNet Pay:   $%.2lf\n\n", netPay);
     
return 0;

}
