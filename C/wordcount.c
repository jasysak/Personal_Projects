/*  wordcount.c -- a simple C program
    that: requires a text file to be
    redirected to it, the program will
    then count the total number of words
	in the document and then calculate
	the average word length in letters,
	then return each value of word count
	and average word length. 
    
    by Jason A. Sysak 10/30/18
    for COP 1220
*/

#include <stdio.h>
#include <ctype.h>

int main(void){    

    // variable declarations
    int ch;
    int chLast;
    int letterCount = 0;    
    int wordCount = 0;
    float averageWordLength = 0;

    // main loop - counting of upper and lower chars, count words based on ch and chLast
    while ((ch = getchar()) != EOF ) {
        if ((islower(ch) || isupper(ch)))
            letterCount++;
		if (((ispunct(ch) && (ch != 39)) || isspace(ch)) && ((islower(chLast) || isupper(chLast))))  
            // N.B. the exclusion of punct ASCII code 39, the ' character. This will NOT count
            // contractions as two words. I.e. "don't" is counted as ONE word by excluding '
            // as a possible terminal character for any word.
            wordCount++;    // if we read a space or punct (excluding '), check for word end 
                            // (if stmt. above) and increment count if TRUE.
        chLast = ch;        // store the last character read for use in determing word end
                            // all valid word ends are either:
                            //      an upper or lower followed by punct
                            //      an upper or lower followed by space
	} // end main loop
    
    // output
    printf( "\nFile Contents:\n" );
    printf( "%d total word count.\n", wordCount );
	printf( "%d total letter count.\n", letterCount );
	averageWordLength = (float)letterCount / wordCount; // this line could be omitted if calc. is done in following line:
    printf( "%.2f average word length.\n\n", averageWordLength );   // (float)letterCount / wordCount in place of averageWordLength is valid
    

    return 0;

}
