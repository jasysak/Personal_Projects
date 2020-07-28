/*	powerfour.c – a simple C program that requests the
	user input a number then passes the number to a 
    function which raises the user inputto the power of four.
    The result is then output to stdout.
    minutes into hours and minutes.
    
	By Jason A. Sysak 10/01/2018.
*/

#include <stdio.h>
#include <math.h>

// function declaration
float powerFunction ( float x, float y );

int main(void)
{
	
    const float EXPONENT = 4.0;
	float userNumber;
    float powerFourResult;
   
	// No input error checking implemented. Code
	// assumes user input is valid float type.
    // Code IS NOT optimized for very small decimal numbers.
    // Changing %0.0f and %0.2f is necessary for use with
    // very small decimals.
	
	printf("\nI will raise your number entry below to the power of %0.0f.\n", EXPONENT);
	printf("\nPlease enter your number: ");
	scanf("%f", &userNumber);
	
    // call to powerFunction 
    powerFourResult = powerFunction(userNumber, EXPONENT);
   
    // output user input and returned result
	printf("\n%0.2f raised to the power of %0.0f is: %0.2f\n", userNumber, EXPONENT, powerFourResult);
	
	printf("\nGoodbye!\n\n");
	
	return 0;
}

float powerFunction ( float x, float y )   // function definition
{
    // local "dummy" variable to hold result, and return it to main()
    float p;
    
    // function calculation
    p = powf(x, y);
    
    // return result as p dummy variable
    return(p);
}

/* eof */
