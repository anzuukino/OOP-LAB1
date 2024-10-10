#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days_in_month[month - 1];
}

bool verify_input(int day, int month, int year){
    if (month >= 1 && month <= 12 && day <= daysInMonth(month, year) && day >= 1){
        return 1;
    }
    return 0;
}

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


int dayOfYear(int day, int month, int year) {
    int total_days = 0;
    for (int i = 1; i < month; i++) {
        total_days += daysInMonth(i, year);
    }
    total_days += day;
    return total_days;
}

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
