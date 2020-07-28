/*	divomatic.c – a simple C program that requests the
	user input two numbers of type double then passes both to a 
    function which divides the first by the second, or returns
    a value of -1.0 if the second number is zero.
    The result is then returned and output to stdout.
    
	By Jason A. Sysak 10/08/2018.
*/

#include <stdio.h>
#include <math.h>

// function declaration
double divomatic ( double x, double y );

int main(void)
{
	
	double userFirstEntry;
    double userSecondEntry;
    double divomaticResult;
   
	// No input error checking implemented. Code
	// assumes user input is valid float type.
    
	printf("\nI will divide two 'double' types, the first divided by the second.\n");
	printf("\nPlease enter your first number: ");
	scanf("%lf", &userFirstEntry);
    printf("\nPlease enter your second number: ");
	scanf("%lf", &userSecondEntry);
    
    // call to powerFunction 
    divomaticResult = divomatic(userFirstEntry, userSecondEntry);
   
    // output result
    if (divomaticResult == -1.0)                                // if...else to ensure
        printf("\nThe result is: %0.1lf", divomaticResult);     // -1.0 is output as "-1.0",
    else                                                        // all other results output
        printf("\nThe result is: %lf", divomaticResult);        // with no format (default format)
    
	printf("\n\nGoodbye!\n\n");
	
	return 0;
}

double divomatic ( double x, double y )   // function definition
{
    // local "dummy" variable to hold result, and return it to main()
    double p;
    
    // function calculation
    if (y == 0)
        p = -1.0;
    else p = x / y;
    
    // return result as p dummy variable
    return(p);
}
