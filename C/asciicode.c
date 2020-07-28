/* asciicode.c – a simple program that displays the ASCII character corresponding
   to the ASCII numeric integer value input by the user.
  
   By JAS 09/17/2018.
*/

#include <stdio.h>

int main(void)
{
    int asciiValue;
	char asciiChar;
	
	printf("Coversion of ASCII numeric integer value to ASCII character.\n");
	printf("\nPlease enter a valid ASCII numeric integer value (0 to 127): ");
	scanf ("%d", &asciiValue);
	
	if (asciiValue >= 0 && asciiValue < 128) {
		asciiChar = (char) asciiValue;
		printf("\nThe ASCII value %d is ASCII character %c.\n\n", asciiValue, asciiChar);
	}
	
	else
		printf("\nInvalid ASCII code. Must be between 0 and 127. Exiting.\n\n");
	
	return 0;
}

/* eof */
