// numstat.cpp
//
// A simple c++ program to calculate statistical
// values based on a series of integers entered
// by the user via stdin (console) until a sentinel
// value (99) is entered. User entry is not stored,
// but statistics calculated as the individual values
// are entered. (sum, max, min, count), finally the
// average is then calculated based on the sum 
// and count values and the results output to
// stdout (console)
// 
// For COP 2224
// v1.0 6/2/19
// Jason Sysak
//
# include <iostream>

using namespace std;

int SENTINEL_VALUE = 99;

int tempValue = 0;
int sumValue = 0;
int countValue = 0;
int maxValue = 0;
int minValue = 0;
double averageValue = 0;

int main () {
    // user entry prompts
    // Full error checking not currently implemented.
    // Code assumes user enters valid integer values only
    cout << "\nBasic integer statistical calclator v1.0 (sum, max, min, count, average)\n\n";
    // priming input :
    cout << "Please enter an integer value (99 to end): ";
    cin >> tempValue;
    // test for 99 on priming input so that statistics are only calculated if user input = 99:
    if (tempValue != 99) {
        maxValue = tempValue;
        minValue = tempValue;
        countValue += 1;
        sumValue += tempValue;
    }
    // main loop and calculations until user inputs 99:
    while (tempValue != 99) {
        cout << "Please enter an integer value (99 to end): ";    
        cin >> tempValue;
        // test for 99 here too just to be sure it is not counted as a valid entry:
        // (we do not want 99 included in the statistics calculations)
        if (tempValue != 99) {    
            countValue += 1;
            sumValue += tempValue;
            // check & update min and max if needed:
            if (tempValue > maxValue) {
                maxValue = tempValue;
            }
            if (tempValue < minValue) {
            minValue = tempValue;
            }
        }
    } // end while loop & user entry
    
    // calculate additional stats (only output if legal values were entered)
    if (countValue > 0) {
        // cast sumValue to double to ensure fractional values:
        averageValue = (double)sumValue / countValue;
        // output
        cout << "\nYou entered " << countValue << " values.\n";
        cout << "\nSum = " << sumValue << endl;
        cout << "Average = " << averageValue << endl;
        cout << "Minimum = " << minValue << endl;
        cout << "Maximum = " << maxValue << endl << endl;
    }
    else {
        cout << "\nNo legal values to calculate were entered. Exiting.\n\n";  
    }
}
// EOF
