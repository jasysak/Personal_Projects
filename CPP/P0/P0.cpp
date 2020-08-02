//
// p0.cpp 
// a simple C++ program to calculate your age from
// a user entered date (i.e. today) and the user
// entered birth date. Note that leap years are not
// considered at this time.
//
// No user entry error checking is implemented. Code
// requires and assumes user entry is valid bumbers
// in the format:
// YYYY MM DD
// (OR)
// YYYY
// MM
// DD
//
// for COP 2224
// Assignment P0
// 05/17/19
// By: Jason Sysak
//
#include <iostream>

int main()
{
    int birth_year;
    int birth_month;
    int birth_day;
    int now_year;
    int now_month;
    int now_day;
	
	const int MONTHS = 12;
    
    // No. of days per month array, no leap years considered
    int days_per_month[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    
	// Array for cumulative days in year for each month
	int cumulative_days[MONTHS]{0};
	
    // A simple for loop to sum days per year
	// (just for practice. We know its normally 365!)
    int sum = 0;
    for(int i = 0; i < MONTHS; ++i){
        sum += days_per_month[i];
		// accumulate days passed in year at the end of each month
		cumulative_days[i] = sum; 
		// this value will be used for determing days between today
		// and year start and days between birth day and year end.
    }
	// Next line for a quick ad-hoc debug
    std::cout << "Calculated days per year: " << sum << "\n";

	std::cout << "Enter date today <year month day>: ";
	std::cin >> now_year >> now_month >> now_day;
    std::cout << "Enter birth date <year month day>: ";
    std::cin >> birth_year >> birth_month >> birth_day;
    
    // Full years not including this year and year of birth.
	// Note one year subtracted and will be "added back" when
	// determining days from today to beginning of year and 
	// days from birth day to end of year.
    int full_years = now_year - birth_year - 1;
    
    // Days from today to beginning of current year to add back
    int days_this_year = 0;
    days_this_year = now_day + cumulative_days[now_month - 1];
    
    // Days from birth date to end of birth year to add back
    int days_birth_year = 0;
    days_birth_year = cumulative_days[11] - ( birth_day + cumulative_days[birth_month - 1] ) ;
    
	// Now add back the last two calculated values
    int total_days = days_this_year + days_birth_year;
    
    double age = full_years + total_days / (double)sum;
    std::cout << "You are " << age << " years old\n";
    
    return 0;
}
