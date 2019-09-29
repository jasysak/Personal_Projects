// grades.cpp
//
// A simple c++ program to determine a letter grade
// based on user entry of a double value (points).
// Grade range from 0 to 100
// Grade scale is 
// A: >=90
// B: >= 80, <90
// C: >=70, <80
// D: >=60, <70
// F: < 60
//
// Program will include a function called LetterGrade that
// takes the user input points value and returns a letter 
// based on the above scale (as a char primitive type)
//
// For COP 2224
// 6/15/19
// Jason Sysak
//
# include <iostream>
#include <limits>

using namespace std;

// Constants for cutoff points for each letter grade.
// Note that B_MAX = A_MIN, and likewise for each lower
// pair. That is, a B_MAX is not needed and A_MIN can
// be used for the same purpose (and likewise again for
// each lower pair).
const double A_MAX = 100.0;
const double A_MIN = 90.0;
const double B_MIN = 80.0;
const double C_MIN = 70.0;
const double D_MIN = 60.0;
const double F_MIN = 0.0;

// variable declarations used in main()
double score = 0.0;
char studentGrade;

// function declaration
char points_to_letter_grade(double points);


// function points_to_letter_grade simply returns
// a letter grade based on the points pointsd which
// is passed to the function as a double value. Valid 
// pointss are 0.0 to 100.0. All others will assign and
// return a lower case 'x'.
char points_to_letter_grade (double points) { 

    // local variable declaration used in points_to_letter_grade()
    char letterGrade;
 
    // Assign proper letter grade
    // first check if passed value is valid, then if so assign the
    // letter grade.
    if (points <= A_MAX && points >= F_MIN) {
         if  (points >= A_MIN) {
            letterGrade = 'A';
        }
        else if (points >= B_MIN && points < A_MIN) {
            letterGrade = 'B';
        }
        else if (points >= C_MIN && points < B_MIN) {
            letterGrade = 'C';
        }
        else if (points >= D_MIN && points < C_MIN) {
            letterGrade = 'D';
        }
        else {
            letterGrade = 'F';
        }
    }
    // an else case for invalid passed value:
   else {
       letterGrade = 'x';
   }
    // single return statement   
    return letterGrade;
}

int main () {
    // basic user entry prompt. No error checking implemented but
    // points_to_letter_grade() will return 'x' for all invalid user entry
    // (provided it is a valid double).
    cout << "\nThe letter grade determinator.\n\n";
    cout << "Please enter a score (0.0-100.0) to determine the letter grade: ";
    cin >> score;
    // code below implements a very basic error check for user entry
    // that is not a valid double:
    while (cin.fail()) { // check for input error (non-double)
        cin.clear();
        // ignore cin until end of line (all input).
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Prompt for re-entry
        cout << "Invalid entry. Please try again." << endl;
        cout << "Please enter a score (0.0-100.0) to determine the letter grade:";
        cin >> score;
    }
    
    // call function and assign char letter grade based on score: 
    studentGrade = points_to_letter_grade(score);
    
    // basic output of the letter grade:
    cout << "\nThe grade is: " << studentGrade << endl << endl;
}
// EOF

