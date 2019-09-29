//
// zMessage.cpp
// 
// Compiled and tested using:
// g++ (GCC) 9.1.1 20190503 (Red Hat 9.1.1-1)
//
// Two basic voicemail child classes (vMail and tMail) for practice
/// deriving child classes from parent (zMessage) classes.
//
// A simple main() is included as a test driver and to demonstrate
// the child classes have been created and function as intended.
//
// NOTE! For the child classes (vMail and tMail) two set method 
// variations have been created -- see below. The "direct calculation"
// method has been commented out, since it is likely not the best 
// way to do this. Using a direct calculation approach, any changes
// to the setPrice calculation would then need to be carried through
// ALL child classes that implemented it. In the case where the child
// class(es) call the inherited setPrice, only a single method (the
// parent method containing setPrice, in this case zMessage) would
// need edits if one were to change the calculation of "price".
//
// "The set method must populate the price of the message based 
// on the length of the message" i.e. each child setLength calls
// setPrice. But setPrice could also be called in main() right after
// each setLength is called (probably the former, per the assignment
// description is the better way though!).
//
// NOTE ALSO: A number of cout "ad-hoc" debug statements used 
// during coding have been left in but commented out!
//
// For COP 2224
// Project P5
// July 21, 2019
// by: Jason Sysak
//

#include <iostream>

using namespace std;

// The following const could be considered global, but I have
// chosen to declare them as private class members. In a "real
// world" scenario it might make more sense for them to be 
// globals.
// const double CENTS_PER_MIN = 17.0;
// const double CENTS_PER_CHAR = 6.0;
// Late addition note: also since these const have been declared
// private, they cannot be used in the main() method! (It would have
// been nice in the output to print the CENTS_PER_XXXX values just
// as a quick check of the calculation!)

class zMessage {
    // zMessage is a basic superclass from which child classes will be derived
    public:
        float price;
        // default no-arg constructor (not used or needed, but I've included it.)
        // (Since this is a parent "prototype" class, I believe a constructor of any
        // type is not needed.)
        zMessage() {
            price = 0;
        }
        // basic get method
        float getPrice() {
           return price;
        }
        // basic set method
        void setPrice(float theUnit, float CENTS_PER_UNIT) {
            price = theUnit * CENTS_PER_UNIT;
        }
}; // end zMessage

class vMail : public zMessage {
    // vMail child of zMessage -- "extends"
    // local "float field for length of message..."
    // (I would likely have used a double here, but assignment
    // description specifies float.)
    float lengthMins;
    private:
        const float CENTS_PER_MIN = 17.0;
    public:
        // default no-arg constructor
        vMail() {
            // cout << "Default vMail constructor invoked.\n";
            lengthMins = 0;
        }
        // basic get method
        float getLength() {
            // cout << "vMail getLength method called.\n";
            return lengthMins;
        }
        // basic set method
        void setLength(float theLength) {
            // cout << "vMail setLength method called.\n";
            lengthMins = theLength;
            setPrice(lengthMins, CENTS_PER_MIN);
            // since price is inherited from zMessage, we could also directly set it here:
            // price = theLength * CENTS_PER_MIN;
            // However, this is likely a bad idea -- see intro. NOTE above.
        }
}; // end vMail

class tMail : public zMessage {
    // tMail child of zMessage -- "extends"
    // local "int field for the number of characters..."
    int lengthChar;
    private:
        const float CENTS_PER_CHAR = 6.0; // this could be an int, I chose to use float
    public:
        // default no-arg constructor
        tMail() {
            // cout << "Default tMail constructor invoked.\n";
            lengthChar = 0;
        }
        // basic get method
        int getLength() {
            // cout << "tMail getLength method called.\n";
            return lengthChar;
        }
        // basic set method
        void setLength(int theLength) {
            // cout << "tMail setLength method called.\n";
            lengthChar = theLength;
            // call setPrice to assign a value to "price"
            setPrice(lengthChar, CENTS_PER_CHAR); // note that arguments here are int, float!
            // since "price" is inherited from zMessage, as above we could also directly set it here:
            // price = lengthChar * CENTS_PER_CHAR;
            // However, this is likely a bad idea -- see intro. NOTE above.
        }
}; // end tMail

int main() {
    // variable used for user entry:
    float messageLengthEntryFloat;
    int messageLengthEntryInt;
    cout << "\nVoicemail zMessage (parent), vMail (child), and tMail (child)";
    cout << "\nclasses with inheritance demo. vMail and tMail are derived ";
    cout << "\nclasses from zMessage." << endl;
    // cout << "\nCreating a vMail object...";
    vMail vMail01;
    // below we will read user input for vMail and tMail length. Normally (i.e. real world) 
    // this  var would likely be calculated from an actual voice mail message. User input
    // is for simple testing and learning purposes here.
    cout << "\nEnter length of vMail message (in minutes!): "; 
    cin >> messageLengthEntryFloat;
    // call vMail setLength()
    vMail01.setLength(messageLengthEntryFloat);
    // test vMail method getLength() and inherited method getPrice(), also
    // verifies the setLength called above was successful.
    cout << "\nThe vMail length is: " << vMail01.getLength() << " minutes." << endl;
    cout << "The vMail price is: " << vMail01.getPrice() << " cents." << endl;
    // cout << "\nCreating a tMail object...";
    tMail tMail01;
    cout << "\nEnter length of tMail message (in characters): "; 
    cin >> messageLengthEntryInt;
    // call tMail setLength()
    tMail01.setLength(messageLengthEntryInt);
    // test tMail method getLength() and inherited method getPrice(), also
    // verifies the setLength called above was successful.
    cout << "\nThe tMail length is: " << tMail01.getLength() << " characters." << endl;
    cout << "The tMail price is: " << tMail01.getPrice() << " cents." << endl << endl;
    //
    // Per my email -- I have added the section below. Not sure if this is required.
    // UPDATE -- section commented out per your response. The setPrice method is
    // called by the child classes, so an explicitly demonstration of setPrice is not
    // necessary.
    //
    // BEGIN COMMENTED CODE
    //
    // double theUnitsEntry;
    // double user_CENTS_PER_UNIT; // this is normally a constant, used in child classes.
    // zMessage zMessage01;
    // cout << "Instantiated zMessage01 using default no-arg constructor." << endl;
    // cout << "This is a parent protoype class. A 'units' and 'CENTS_PER_UNIT' is needed." << endl;
    // cout << "Enter units: ";
    // cin >> theUnitsEntry;
    // cout << "Enter a CENTS_PER_UNIT: ";
    // cin >> user_CENTS_PER_UNIT;
    // zMessage01.setPrice(theUnitsEntry, user_CENTS_PER_UNIT);
    // cout << "\nThe zMessage01 price is: " <<  zMessage01.getPrice() << endl << endl;
    //
    // END COMMENTED CODE
    //
    return 0;
} // EOF
