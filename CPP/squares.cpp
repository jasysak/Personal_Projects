// squares.cc
//
// A simple c++ program to determine if user entry of
// two points in space, x and y, are a perfect square,
// in landscape orientation, or portrait orientation.
//
// For COP 2224
// 5/30/19
// Jason Sysak
//
# include <iostream>

using namespace std;

// initialize both dimensions as -1 to allow
// a simple test that user entry is a valid
// positive dimension
int x_HorizontalDim = -1;
int y_VerticalDim = -1;

int main () {
    // user entry prompts
    // Full error checking not currently implemented.
    cout << "\nThe square and rectangle test.\n";
    cout << "Please enter only positive, whole integer values!\n\n";
    cout << "Enter the X (horizontal) dimension: ";
    // a basic test for valid positive dimensions using
    // priming input and while loops:
    cin >> x_HorizontalDim;
    while (x_HorizontalDim <=0) {
        cout << "ERROR - dimension must be a positive integer!";
        cout << "\nRe-Enter the X (horizontal) dimension: ";
        cin >> x_HorizontalDim;
    }
    cout << "Enter the Y (vertical) dimension: ";
    cin >> y_VerticalDim;
    while (y_VerticalDim <=0) {
        cout << "ERROR - dimension must be a positive integer!";
        cout << "\nRe-Enter the Y (vertical) dimension: ";
        cin >> y_VerticalDim;
    }
    
    // if logic to check shape orientation
    // Since dimension entry should be arbitrary, no case is more likely
    // than any other. Thus specific ordering of the if logic tests is not
    // necessary (The most likely outcome(s) generally should be tested
    // first).
    if (x_HorizontalDim == y_VerticalDim) {
        cout << "\nThe shape is a perfect square.\n\n";
    }
    else if (x_HorizontalDim > y_VerticalDim ) {
             cout << "\nThe shape is a rectangle in landscape orientation.\n\n";
    }
    else {  // since this option is the only one left, an additional
            // test is not needed.
        cout << "\nThe shape is a rectangle in portrait orientation.\n\n";
    }
}
// EOF

