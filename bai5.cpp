#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

/**
 * Checks if a given year is a leap year.
 * A leap year is divisible by 4, but not by 100, unless it is divisible by 400.
 * 
 * @param year The year to be checked.
 * @return true if the year is a leap year, false otherwise.
 */

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * Returns the number of days in a given month of a year.
 * 
 * @param month The month for which the number of days is to be calculated.
 * @param year The year in which the month falls.
 * @return The number of days in the given month.
 */

int daysInMonth(int month, int year) {
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days_in_month[month - 1];
}

/**
 * Verifies the input date.
 * The month must be between 1 and 12, and the day must be between 1 and the number of days in the month.
 * 
 * @param day The day of the date.
 * @param month The month of the date.
 * @param year The year of the date.
 * @return true if the date is valid, false otherwise.
 */

bool verify_input(int day, int month, int year){
    if (month >= 1 && month <= 12 && day <= daysInMonth(month, year) && day >= 1){
        return 1;
    }
    return 0;
}

/**
 * Advances the date to the next day.
 * If the day is the last day of the month, it is set to 1, and the month is advanced.
 * If the month is December, the month is set to January, and the year is advanced.
 * 
 * @param day The day of the date.
 * @param month The month of the date.
 * @param year The year of the date.
 */

void nextDay(int& day, int& month, int& year) {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

/**
 * Moves the date to the previous day.
 * If the day is the first day of the month, it is set to the last day of the previous month.
 * If the month is January, the month is set to December, and the year is decremented.
 * 
 * @param day The day of the date.
 * @param month The month of the date.
 * @param year The year of the date.
 */

void previousDay(int& day, int& month, int& year) {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
}

/**
 * Calculates the day of the year for a given date.
 * The day of the year is the sum of the days in the months preceding the given month, plus the day of the month.
 * 
 * @param day The day of the date.
 * @param month The month of the date.
 * @param year The year of the date.
 * @return The day of the year for the given date.
 */

int dayOfYear(int day, int month, int year) {
    int total_days = 0;
    for (int i = 1; i < month; i++) {
        total_days += daysInMonth(i, year);
    }
    total_days += day;
    return total_days;
}

/**
 * Main function to demonstrate the date manipulation functions.
 * The user is prompted to input a date, and the program calculates the next and previous days, the day of the year,
 * and prints the results.
 * 
 * @return 0 on successful execution
 * 
 */

int main() {
    int day, month, year;
    int ok = 0;
    while (!ok){
        cout << "Nhap ngay (dd mm yyyy): ";
        cin >> day >> month >> year;
        ok = verify_input(day,month,year);
    }
    
    int next_day = day, next_month = month, next_year = year;
    nextDay(next_day, next_month, next_year);
    cout << "Ngay ke tiep: " << next_day << "/"  << next_month << "/" << next_year << endl;

    int prev_day = day, prev_month = month, prev_year = year;
    previousDay(prev_day, prev_month, prev_year);
    cout << "Ngay truoc do: " << prev_day << "/" << prev_month << "/" << prev_year << endl;

    int day_in_year = dayOfYear(day, month, year);
    cout << "Ngay nay la ngay thu " << day_in_year << " trong nam." << endl;

    return 0;
}
