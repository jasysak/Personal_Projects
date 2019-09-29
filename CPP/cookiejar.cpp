// 
// cookiejar.cpp
//
// A simple c++ program  to implement a basic class representing
// a cookie jar. 
//
// Class CookieJar specifications:
// Default maximum cookie content = 12 (MAX_COOKIES_DEFAULT)
// Default constructor using default maximum cookie content 
// Parameterized constructor allowing assignment of actual and maximum cookie content
// Set method to add cookie(s) to jar
// Set method to subtract cookie(s) from jar
// Set method to completely empty cookie jar when maximum cookie content is reached (or exceeded)
// Get method to display current jar cookie count
//
// A basic main() method is included for implementation and testing of the CookieJar class.
//
// For COP 2224
// 7/14/2019
// Submitted 7/22/19 (Late)
// by: Jason Sysak
//
#include <iostream>

using namespace std;

// constant for the default maximum cookies in any jar.
// I decided to declare this with global scope, however it could
// also be declared within CookieJar to limit it's scope to the
// CookieJar class only (and further as a private member). I
// made this decision early on with the thought I might need 
// to use this value in the main() method for testing.
const int MAX_DEFAULT_COOKIES = 12;

// global vars - used for testing purposes
int theCookies = 5; // test -- cookie count for Jar01
int theMaxCookies = 10; // test -- cookie max. count for jar01
int theJarDelta;  // delta: test for both add and subtract
int newMaxCookies; // test for setMaxCookies()

class CookieJar {
    public:
        int cookies;
        int maxCookies;
    // default constructor
    CookieJar() {
        cout << "default constructor.\n";
        cookies = 0;
        maxCookies = MAX_DEFAULT_COOKIES;
    } // tested...OK
    
    // constructor w/ 2 int parameters: desired cookies in the jar, maximum cookies jar can hold
    CookieJar(int theCookies, int theMaxCookies) {
        cout << "parameterized constructor.\n";
        cookies = theCookies;
        maxCookies = theMaxCookies;
    } // tested...OK
    
    void emptyJar() {
        //cout << "Empty jar method invoked.\n";
        cookies = 0;
    } // tested...OK
    
    int countCookies() {
        //cout << "Count cookies method invoked.\n";
        return cookies;
    } // tested...OK
    
    void addCookies(int addCookie) {
        //cout << "Add cookies method invoked.\n";
        cookies += addCookie;
    } // tested...OK
    
    void subtractCookies(int subtractCookie) {
        //cout << "Subtract cookies method invoked.\n";
        cookies -= subtractCookie;
    } // tested...OK
    
    void setMaxCookies(int theMaxCookies) {
        //cout << "Set Max. Cookies method invoked.\n";
        maxCookies = theMaxCookies;
    } // tested...OK
    
    int getMaxCookies() {
        //cout << "Query max cookies method invoked.\n";
        return maxCookies;
    } // tested...OK
    
}; // end CookieJar()

// begin main() TEST CODE
// Code includes some basic checking for invalid values (i.e. add more cookies to
// a jar than the max. it can hold), but the testing is LIMITED AND SHOULD NOT 
// BE CONSIDERED COMPLETE OR COMPREHENSIVE!
int main() {
    //
    // test construct Jar00 with default constructor, also test countCookies() and getMaxCookies():
    //
    cout << "\nJar 00 is constructed with ";
    CookieJar jar00;
    cout << "It contains " << jar00.countCookies() << " cookies and can hold a maximum of " << jar00.getMaxCookies() << " cookies.\n";
    //
    // test construct Jar01 with parameterized constructor,  also test countCookies() and getMaxCookies():
    //
    cout << "\nJar 01 is constructed with ";
    CookieJar jar01(theCookies, theMaxCookies);
    cout << "It contains " << jar01.countCookies() << " cookies, and can hold a maximum of ";
    cout << jar01.getMaxCookies() << " cookies.\n" << endl;
    //
    // test addCookies() and emptyJar():
    //
    cout << "Adding cookies to Jar01. Enter cookies to add (max. " << jar01.getMaxCookies() << "): ";
    cin >> theJarDelta;
    // check for exceeding max.
    if  (  ( theJarDelta + jar01.countCookies() ) > jar01.getMaxCookies() ) {
        cout << "The added cookies (" << theJarDelta << ") causes Jar01 to exceed the maximum it can hold.\n";
        // Second check for theJarDelta alone exceeding max.
        // in this case, we simply set theJarDelta equal to the max.
        if ( theJarDelta > jar01.getMaxCookies() ) {
            cout << "WARNING - Because the entered cookies to add exceeds the maximum the jar can ";
            cout << "hold, setting added cookies to maximum! (" << jar01.getMaxCookies() << ").\n";
            theJarDelta = jar01.getMaxCookies(); 
        }
        cout << "Now emptying Jar 01 and re-adding " << theJarDelta << " cookies.\n";
        jar01.emptyJar();
    }
     jar01.addCookies(theJarDelta);
    cout << "\nJar 01 now contains " << jar01.countCookies() << " cookies and can hold a maximum of " << jar01.getMaxCookies() << " cookies.\n";
    //
    // test subtractCookies():
    //
    cout << "\nSubtracting cookies to Jar01. Enter cookies to subtract (max. " << jar01.countCookies() << "): ";
    cin >> theJarDelta;
    if  (  ( jar01.countCookies() - theJarDelta ) < 0 ) {
        cout << "WARNING - The subtracted cookies (" << theJarDelta << ") exceeds Jar 01 contents (" << jar01.countCookies() << ").\n";
        cout << "The jar will be emptied.\n";
        cout << "Now emptying Jar 01.";
        jar01.emptyJar();
    } else {
         jar01.subtractCookies(theJarDelta);
    }
    cout << "\nJar 01 now contains " << jar01.countCookies() << " cookies and can hold a maximum of " << jar01.getMaxCookies() << " cookies.\n";
    //
    // test setMaxCookies():
    //
    cout << "\nModify maximum cookie count for Jar 00. Specify a new maximum: ";
    cin >> newMaxCookies;
    jar00.setMaxCookies(newMaxCookies);
    cout << "\nJar 00 contains " << jar00.countCookies() << " cookies and can hold a maximum of " << jar00.getMaxCookies() << " cookies.\n\n";
    return 0;
} // EOF
