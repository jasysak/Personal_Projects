/*  calc_project.c -- 

    A very basic RPN calculator simulator.
    
    Simulates the operation of a reverse polish
    notation calculator like the HP48 series.
    
    The basic RPN calculators written in C I've
    found are single-line calculators, where a 
    single line of values and operators is evalutated
    "all at once". My version may bear some similarity,
    but will also allow storing of up to (20) user entered
    values in "memory" (an array), and various basic math
    operations can be performed on the values stored. The
    stored values will persist and be displayed.
    
    The first revision will allow only a single
    operation to be specified (+, -, *, /) and
    performed on the last 2 values entered (last 2 
    values stored in the memory array). The array will 
    be updated and re-displayed with the new (result)
    value replacing the two operands. This is the typical
    operation of any RPN calculator - that the operands of
    any function are replaced with the result (the code 
    can be changed to retain the operands if so desired).
    
    The user may also simply input numbers. These will
    be individually stored in the memory array until the
    maximum of 20 values is reached. Once this occurs the 
    20th value will be dropped ("erased from memory") to
    maintain the maximum of 20 values stored. Note the 20
    value maximum has been arbitrarily selected to limit 
    the scope and to allow all values in memory to be
    displayed on a standard 24-line terminal window.
    
    If time permits, I plan to expand the capability to
    allow the user to specify a series of operations
    as part of a single input to be performed as an RPN
    calculator would. I would also like to expand the
    input capability, as it is very simplistic at this time,
    allowing the user to input multiple values all at once on
    a single line, separated by spaces, along with operators
    if desired.
    
    by Jason A. Sysak 12/01/18
    for COP 1220, Fall 2018
    Semester End Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MEM_SIZE 20     // max. 20 values stored in memory
#define MAX_LEN 100     // max. length of each entry

double calcMemory[MEM_SIZE] = {0.0};    // "stack" array. All values stored in calc memory 

// function declaration
void drawScreen();
void push(double num);
void swap();
void load();
void drop();
void echo(double num);

int main(void)
{    
    // varaible declaration
    char entry;                  // temp var & to check if math function specified
    char entryBuffer[MAX_LEN];  
    
    // (re)draw screen - initial (is repeated after each user entry)
    drawScreen();
    
    // initial prompt for entry and logic to determine action
    printf("Enter a number, operation (+, -, *, /, (S)wap, (D)rop, (E)cho (Q)uit): ");
    scanf("%s", entryBuffer);   // I think there is a better way to do this with getchar()
    entry = entryBuffer[0];
    while (entry != 'Q')
    {
	        // note that I started with a switch instead of this giant if...if else...else
            // but was not able to get it working properly in time. Poor form here, IMO. 
            if(isdigit(entry))
            {
			    load(strtod(entryBuffer, NULL));    // convert string to double
            }
		    else if (entry == '+')                  // I think there is a better way to do this.
                                                    
            {
			    push(calcMemory[1] + calcMemory[0]);
            }
			else if (entry == '-')
            {
			    push(calcMemory[1] - calcMemory[0]);
            }
            else if (entry == '*')
            {
			    push(calcMemory[1] * calcMemory[0]);
            }
			else if (entry == '/')
            {
			    if (calcMemory[0] == 0)
                {
                    printf("Divide by zero error. Exiting.\n"); // I intend to not just break on a div. by zero.
                    break;                                      // Will expand on this, time permitting.
                }
                else push((double)calcMemory[1] / (double)calcMemory[0]);   // typecast required here to ensure
                                                                            // a proper result
            }
            else if (entry == 'S' )
                swap();
            else if (entry == 'E' )
                echo(calcMemory[0]);
            else if (entry == 'D' )
                drop();
	        else
			printf("Error. Invalid entry: %d\n", entry);    // this may never get executed. Invalid entry simply
                                                      // does nothing.
        drawScreen();   // redraw after each entry/operation
        fflush(stdin);  // Late addition -- otherwise I was getting repeat values from previous scanf
        
        // re-display user entry prompt. (I could have made a user entry prompt function...or combined it with drawScreen()
        printf("Enter a number, operation (+, -, *, /, (S)wap, (D)rop, (E)cho (Q)uit): ");
        scanf("%s", entryBuffer);
        entry = entryBuffer[0];
    }
    return 0;
    
} // end main
    
// function drawScreen    
void drawScreen()
{
    // clear and re-draw screen code - note that last entry is index 0.
    // loop is "in reverse" index 19 to 0
    system("clear");    // Note this is Linux specific.
    // system("cls");   // For windows based platforms (untested).
    
    printf("Memory Contents:\n");
    for (int i = (MEM_SIZE-1); i >= 1; i--)
        printf("%2.0d : %lf\n", i, calcMemory[i]);
        printf(" 0 : %lf\n", calcMemory[0]);    // I got frustrated in that my loop wasn't printing the last line properly,
                                                // leaving off the index 0 (zero). So I just manually printed the last entry.
                                                // ...very poor form here, IMO.
    return;
}  // end function drawScreen

// function load - simple loading of the stack with numbers.
void load(double num)
{
    for (int i = (MEM_SIZE-1); i > 0; i--)
        calcMemory[i] = calcMemory[i-1];
    calcMemory[0] = num;
    return;
}   // end function load
    
// function push - place number (num) into stack array at index 0.
// Shift all other values down by 1. 
// Called by any calculation.
void push(double num)
{
    for (int i = 1; i < MEM_SIZE; i++)
        calcMemory[i] = calcMemory[i+1];
    calcMemory[0] = (double)num;
    return;
}   // end function push
    // Note push also used for swap with calcMemory[0] as num

// swap function. Simple swap of last two entered values (array index 1 and index 0)
// commonly used on RPN calculators, but may not be intuitive for non-RPN users.
void swap()
{
    double temp0 = calcMemory[0];
    double temp1 = calcMemory[1];
    calcMemory[0] = temp1;
    calcMemory[1] = temp0;
    return;
}   // end function swap

// drop function. Simply delete the last entered value (calcMemory[0])
// -> shift all previous calcEntry[#] down, calcMemory[0] gets replaced.
void drop()
{
    for (int i = 0; i < MEM_SIZE; i++)
        calcMemory[i] = calcMemory[i+1];
    return;
}   //  end function drop

// echo function. Simply duplicates last value (calcMemory[0])
// all other values shifted up one place.
void echo(double num)
{
    for (int i = (MEM_SIZE-1); i > 0; i--)
        calcMemory[i] = calcMemory[i-1];
    calcMemory[0] = (double)num;
    return;
}   // end function echo

// EOF
