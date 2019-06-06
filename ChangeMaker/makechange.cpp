//
// makechange.cpp
//
// A simple C++ program to make change based on user
// input of balance due and payment amount.
//
// Change is calculated as integer values of:
// whole dollars
// quarters
// dimes
// nickels
// pennies
//
// Notes / Assumptions:
// 1. Initial version contained no error checking. Version 1.1
//    now includes via while loops. Credit to stack overflow and
//    cppreference.com for help on this:
//    https://stackoverflow.com/questions/28635130/input-error-checking-in-c
//    https://en.cppreference.com/w/cpp/types/numeric_limits
// 2. Program is written to execute once with single inputs.
//    (If user desires a new claculation, program must be re-run.)
// 3. No procedures/functions are implemented, but could very easily be for
//    the calc. of each change type and myRemainder. This could serve
//    as a "prototype" for any cash-register type of program.
// 4. Compiled and tested using g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
// 5. floats were originally used but appeared to result in minor rounding
//    errors when user entry was large vaues so were changed to double in v1.1.

// for COP 2224
// May 26, 2019
// by Jason Sysak
//
// v1.0 05/25/19 - basic version, no error checking of user input
// v1.1 05/26/19 - error checking of user input implemented, 
//                 change all float to double.
//
// basic includes
#include <iostream>
// #include <math.h>  NO LONGER NEEDED

// the following include is needed for the
// cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// statements in the error checking.
#include <limits>

using namespace std;

double VERSION_NUMBER = 1.1;

// We will use a constant to convert all
// user input to CENTS
int CENTS_CONVERT = 100;

// Conversion factors for each of dollars, quarters, dimes,
// nickels, and pennies to cents:
int DOLLAR_CENTS = 100;
int QUARTER_CENTS = 25;
int DIME_CENTS = 10;
int NICKEL_CENTS = 5;
int PENNY_CENTS = 1;

// myRemainder variable will (temp) hold the myRemainder after
// each conversion calculation.
int myRemainder = 0;

// other variables for user input and corresponding int values
double paymentAmount;
double balanceDue;

// I chose to use separate, explicit vars for the corresponding
// int types, but the above doubles could be type cast to int instead.
int paymentAmountInt;
int balanceDueInt;

// variable to hold the total change due in #### format
// (units of CENTS)
int changeTotal;

// variable for conversion calculation and output
int changeDollars;
int changeQuarters;
int changeDimes;
int changeNickels;
int changePennies;

int main()
{
    // User Input - error check implemented via while blocks
    cout << "\nChange Calculator v" << VERSION_NUMBER << "\n";
    cout << "\nEnter balance due in dollars and cents (##.##): ";
    cin >> balanceDue;
    while (cin.fail()) { // check for input error (non-double)
        cin.clear();
        // ignore cin until end of line (all input).
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Prompt for re-entry
        cout << "You entered an incorrect value. Try again" << endl;
        cin >> balanceDue;
    }
    
    cout << "Enter payment amount in dollars and cents (##.##): ";
    cin >> paymentAmount;
    while (cin.fail()) { // check for input error (non-double)
        cin.clear();
        // ignore cin until end of line (all input).
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Prompt for re-entry
        cout << "You entered an incorrect value. Try again" << endl;
        cin >> paymentAmount;
    }
      
    // Convert amounts to CENTS (* 100) makes the following
    // calculations simpler:
    balanceDueInt = balanceDue * CENTS_CONVERT;
    paymentAmountInt = paymentAmount * CENTS_CONVERT;   
    // Calculation of change per each type consiting of dollar,
    // quarter dime, nickel, penny. This sequence should also 
    // ensure the fewest of each type is provided.
    changeTotal = paymentAmountInt - balanceDueInt;
    changeDollars = changeTotal / DOLLAR_CENTS;
    myRemainder = changeTotal % DOLLAR_CENTS;
    changeQuarters = myRemainder / QUARTER_CENTS;
    myRemainder = myRemainder % QUARTER_CENTS;
    changeDimes = myRemainder / DIME_CENTS;
    myRemainder = myRemainder % DIME_CENTS;
    changeNickels = myRemainder / NICKEL_CENTS;
    myRemainder = myRemainder % NICKEL_CENTS;
    changePennies = myRemainder;
    
    // Output
    cout << "\nThe change due is: \n\n";
    cout << changeDollars << " Dollars\n";
    cout << changeQuarters << " Quarters\n";
    cout << changeDimes << " Dimes\n";
    cout << changeNickels << " Nickels\n";
    cout << changePennies << " Pennies\n\n";
    cout << "For a total of: $" << (double)changeTotal / CENTS_CONVERT << endl << endl;
    
    return 0;
}
// EOF
