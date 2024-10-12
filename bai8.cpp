#include <iostream>
#include <string>
#include <regex>
#include <ctime>

using namespace std;

/**
 * Struct to store information of a flight.
 * The information includes the flight code, date, time, departure and arrival locations.
 */

struct Flight {
    string MaChuyenBay;
    int Ngaybay;
    int Thangbay;
    int Nambay;
    int Giobay;
    int Phutbay;
    string Noidi;
    string Noiden;
};

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
 * Checks if a given string is a valid flight code.
 * A valid flight code contains between 1 and 5 alphanumeric characters.
 * 
 * @param code The string to be checked.
 * @return true if the string is a valid flight code, false otherwise.
 */
bool isValidFlightCode(const string &code) {
    regex pattern("^[A-Za-z0-9]{1,5}$");
    return regex_match(code, pattern);
}

/**
 * Checks if a given string is a valid place name.
 * A valid place name contains between 1 and 20 alphabetic characters or spaces.
 * 
 * @param place The string to be checked.
 * @return true if the string is a valid place name, false otherwise.
 */
bool isValidPlace(const string &place) {
    regex pattern("^[A-Za-z\\s]{1,20}$");
    return regex_match(place, pattern);
}

/**
 * Checks if a given string is a valid time.
 * A valid time is in the format "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59.
 * 
 * @param time The string to be checked.
 * @return true if the string is a valid time, false otherwise.
 */
bool isValidTime(const string &time) {
    regex pattern("^([01][0-9]|2[0-3]):([0-5][0-9])$");
    return regex_match(time, pattern);
}

/**
 * Parses a time string in the format "HH:MM" and stores the hours and minutes in a Flight object.
 * 
 * @param time The time string to be parsed.
 * @param flight The Flight object in which to store the hours and minutes.
 */
void parseTime(const string &time, Flight &flight) {
    flight.Giobay = stoi(time.substr(0, 2));
    flight.Phutbay = stoi(time.substr(3, 2));
}

/**
 * Prompts the user to enter information for a Flight.
 * 
 * @param flight The Flight to be filled with information.
 */
void nhap(Flight &flight){
    do {
        cout << "Nhap ma chuyen bay: ";
        getline(cin, flight.MaChuyenBay);
        if (!isValidFlightCode(flight.MaChuyenBay)) {
            cout << "Ma chuyen bay khong hop le! Vui long nhap lai.\n";
        }
    }while(!isValidFlightCode(flight.MaChuyenBay));
    
    do {
        cout << "Nhap ngay bay (dd mm yyyy): ";
        cin >> flight.Ngaybay >> flight.Thangbay >> flight.Nambay;
        if (!verify_input(flight.Ngaybay, flight.Thangbay, flight.Nambay)) {
            cout << "Ngay bay khong hop le! Vui long nhap lai.\n";
        }
    }while(!verify_input(flight.Ngaybay, flight.Thangbay, flight.Nambay));
    string thoigianbay;
    cin.ignore();
    do {
        cout << "Nhap gio bay (HH:MM): ";
        getline(cin, thoigianbay);
        
        if (!isValidTime(thoigianbay)) {
            cout << "Gio bay khong hop le! Vui long nhap lai.\n";
        }else
            parseTime(thoigianbay, flight);
    }while(!isValidTime(thoigianbay));

    do {
        cout << "Nhap noi di: ";
        getline(cin, flight.Noidi);
        if (!isValidPlace(flight.Noidi)) {
            cout << "Noi di khong hop le! Vui long nhap lai.\n";
        }
    }while(!isValidPlace(flight.Noidi));

    do {
        cout << "Nhap noi den: ";
        getline(cin, flight.Noiden);
        if (!isValidPlace(flight.Noiden)) {
            cout << "Noi den khong hop le! Vui long nhap lai.\n";
        }
    }while(!isValidPlace(flight.Noiden));
}

/**
 * Displays the information of a Flight.
 * 
 * @param flight The Flight to be displayed.
 */
void HienThiThongTinChuyenBay(const Flight &flight) {
    cout << "--------------------------\n";
    cout << "Ma chuyen bay: " << flight.MaChuyenBay << endl;
    cout << "Noi di: " << flight.Noidi << endl;
    cout << "Noi den: " << flight.Noiden << endl;
    cout << "Ngay bay: " << flight.Ngaybay << "/" << flight.Thangbay << "/" << flight.Nambay << endl;
    cout << "Gio bay: " << flight.Giobay << ":" << (flight.Phutbay < 10 ? "0" : "") << flight.Phutbay << endl;
    cout << "--------------------------\n";
}

/**
 * Converts a string to lowercase.
 * 
 * @param s The string to be converted.
 * @return The lowercase version of the string.
 */
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
/**
 * Searches for a flight by flight code, departure, or destination.
 * 
 * @param flight The array of flights.
 * @param tuKhoa The keyword to search for.
 * @param n The number of flights in the array.
 */
void TimKiemChuyenBay(Flight flight[], string tuKhoa, int n) {
    bool found = false;
    string tuKhoaLower = toLower(tuKhoa);
    for (int i = 0; i < n; i++) {
        string MaChuyenBayLower = toLower(flight[i].MaChuyenBay);
        string NoidiLower = toLower(flight[i].Noidi);
        string NoidenLower = toLower(flight[i].Noiden);
        if (MaChuyenBayLower.find(tuKhoaLower) != string::npos || NoidiLower.find(tuKhoaLower) != string::npos || NoidenLower.find(tuKhoaLower) != string::npos ) {
            cout << "Da tim thay chuyen bay: " << endl;
            HienThiThongTinChuyenBay(flight[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay nao voi ten \"" << tuKhoa << "\"\n";
    }
}
/**
 * Searches for flights on a given date.
 * 
 * @param flight The array of flights.
 * @param n The number of flights in the array.
 */
void TimKiemTheoNgay(Flight flight[], int n){
    int Ngay, Thang, Nam;
    do {
        cout << "Nhap ngay bay can tim kiem (dd mm yyyy): ";
        cin >> Ngay >> Thang >> Nam;
        if (!verify_input(Ngay, Thang, Nam)) {
            cout << "Ngay bay khong hop le! Vui long nhap lai.\n";
        }
    }while(!verify_input(Ngay, Thang, Nam));

    bool found = false;
    for (int i = 0; i < n; i++){
        if (flight[i].Ngaybay == Ngay && flight[i].Thangbay == Thang && flight[i].Nambay == Nam){
            cout << "Da tim thay chuyen bay: " << endl;
            HienThiThongTinChuyenBay(flight[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay chuyen bay nao bay vao ngay " << Ngay << "/" << Thang << "/" << Nam << "\n";
    }
}
/**
 * Counts the number of flights from a given departure to a given destination.
 * 
 * @param flight The array of flights.
 * @param n The number of flights in the array.
 * @param noidi The departure location.
 * @param noiden The destination location.
 */
void SoLuongChuyenBay(Flight flight[], int n, string noidi, string noiden){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (toLower(flight[i].Noidi) == toLower(noidi) && toLower(flight[i].Noiden) == toLower(noiden)){
            count++;
        }
    }
    cout << "So luong chuyen bay di tu " << noidi << " den " << noiden << " la: " << count << endl;
}
/**
 * Compares two flights based on their departure date and time.
 * 
 * @param a The first flight.
 * @param b The second flight.
 * @return true if the first flight is earlier than the second flight, false otherwise.
 */
bool sosanh2chuyenbay(Flight a, Flight b){
    if (a.Nambay < b.Nambay){
        return 1;
    }else if (a.Nambay == b.Nambay){
        if (a.Thangbay < b.Thangbay){
            return 1;
        }else if (a.Thangbay == b.Thangbay){
            if (a.Ngaybay < b.Ngaybay){
                return 1;
            }else if (a.Ngaybay == b.Ngaybay){
                if (a.Giobay < b.Giobay){
                    return 1;
                }else if (a.Giobay == b.Giobay){
                    if (a.Phutbay < b.Phutbay){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
/**
 * Main function to manage flights.
 * The program prompts the user to enter information for a number of flights.
 * It then displays the flights sorted by departure date and time.
 * The user can search for a flight by flight code, departure, or destination.
 * The user can also search for flights on a given date or count the number of flights between two locations.
 * 
 * @return 0 on successful execution.
 */
int main(){
    int n;
    cout << "Nhap so chuyen bay: ";
    cin >> n;
    cin.ignore();
    Flight flights[n];
    for (int i = 0; i < n; i++){
        nhap(flights[i]);
    }
    sort(flights, flights + n, sosanh2chuyenbay);

    cout << "\nDanh sach chuyen bay sau khi sap xep theo ngay va gio khoi hanh:\n";
    for (const Flight &cb : flights) {
        HienThiThongTinChuyenBay(cb);
    }

    int choice = 0, ok = 1;
    while(ok){
        cout << "1. Tim kiem chuyen bay theo ma chuyen bay, noi di hoac noi den." << endl;
        cout << "2. Danh sach cac chuyen bay di trong mot ngay." << endl;
        cout << "3. So luong chuyen bay di va den tu 1 noi nhat dinh." << endl;
        cout << "4. Thoat." << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        string tukhoa;
        string noidi;
        string noiden;
        switch (choice){
            case 1:
                cout << "Nhap thong tin cua chuyen bay can tim: ";
                cin.ignore();
                getline(cin, tukhoa);
                TimKiemChuyenBay(flights, tukhoa, n);
                break;
            case 2:
                TimKiemTheoNgay(flights, n);
                break;
            case 3:
                cout << "Nhap noi di cua chuyen bay can tim: ";
                cin.ignore();
                getline(cin, noidi);
                cout << "Nhap noi den cua chuyen bay can tim: ";
                getline(cin, noiden);
                SoLuongChuyenBay(flights, n, noidi, noiden);
                break;
            case 4:
                ok = 0;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    }
    return 0;
}