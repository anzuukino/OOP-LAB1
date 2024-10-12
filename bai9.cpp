#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <iomanip>

using namespace std;

/** 
 * Constants for short-term, long-term, and non-term interest rates.
*/

const double lai_suat_ngan_han = 1.2;
const double lai_suat_dai_han = 2.1;
const double lai_suat_khong_ky_han = 0.5;

/**
 * Struct to store information of a date.
 * The information includes the day, month, and year.
 */

struct Date{
    int day;
    int month;
    int year;
};

/**
 * Struct to store information of a savings account.
 * The information includes the account code, type of savings, customer name, ID card number,
 * opening date, amount deposited, interest rate, and interest amount.
 */

struct SoTietKiem{
    string MaSo;
    string Loai_tiet_kiem;
    string Ho_ten_khach_hang;
    string CMND;
    Date Ngay_mo_so;
    long double So_tien_gui;
    double lai_suat;
    double tien_lai;
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

bool isValidCode(const string &code) {
    regex pattern("^[A-Za-z0-9]{1,5}$");
    return regex_match(code, pattern);
}

/**
 * Checks if a given string is a valid ID card number.
 * A valid ID card number contains either 9 or 12 digits.
 * 
 * @param code The string to be checked.
 * @return true if the string is a valid ID card number, false otherwise.
 */

bool isValidCMND(const string &code) {
    regex pattern("^(\\d{9}|\\d{12})$");
    return regex_match(code, pattern);
}

/**
 * Checks if a given string is a valid name.
 * A valid name contains only alphabetic characters and has a length between 2 and 30 characters.
 * 
 * @param name The string to be checked.
 * @return true if the string is a valid name, false otherwise.
 */

bool isValidName(const string &place) {
    regex pattern("^[A-Za-z\\s]{1,30}$");
    return regex_match(place, pattern);
}

/**
 * Checks if a given string is a valid type of savings.
 * A valid type of savings is either "Ngan han", "Dai han", or "Khong ky han".
 * 
 * @param loai The string to be checked.
 * @return true if the string is a valid type of savings, false otherwise.
 */

bool isValidLoaiTietKiem(const string &loai) {
    regex pattern("^(Ngan han|Dai han|Khong ky han)$");
    return regex_match(loai, pattern);
}


/**
 * Prompts the user to enter information for a savings account.
 * 
 * @param stk The savings account to be filled with information.
 */
void HienThiThongTin(SoTietKiem stk){
    cout << "--------------------------\n";
    cout << "Ma so: " << stk.MaSo << endl;
    cout << "Loai tiet kiem: " << stk.Loai_tiet_kiem << endl;
    cout << "Ho ten khach hang: " << stk.Ho_ten_khach_hang << endl;
    cout << "CMND: " << stk.CMND << endl;
    cout << "Ngay mo so: " << stk.Ngay_mo_so.day << "/" << stk.Ngay_mo_so.month << "/" << stk.Ngay_mo_so.year << endl;
    cout << "So tien gui: " << fixed << setprecision(2) << stk.So_tien_gui << endl;
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
 * Searches for a savings account by account code or ID card number.
 * 
 * @param stk The array of savings accounts.
 * @param tuKhoa The keyword to search for.
 * @param n The number of savings accounts in the array.
 */

void TimKiemTheoMaSo(SoTietKiem stk[], string tuKhoa, int n) {
    bool found = false;
    string tuKhoaLower = toLower(tuKhoa);
    for (int i = 0; i < n; i++) {
        string MaSoLower = toLower(stk[i].MaSo);
        string CMND = stk[i].CMND;
        if (CMND == tuKhoa || MaSoLower == tuKhoaLower) {
            cout << "Da tim thay so tiet kiem: " << endl;
            HienThiThongTin(stk[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay so tiet kiem lien quan den \"" << tuKhoa << "\"\n";
    }
}

/**
 * Compares two savings accounts based on their opening date.
 * 
 * @param a The first savings account.
 * @param b The second savings account.
 * @return true if the first savings account was opened earlier than the second, false otherwise.
 */

bool sosanhngay2stk(SoTietKiem a, SoTietKiem b){
    if (a.Ngay_mo_so.year < b.Ngay_mo_so.year){
        return 1;
    }else if (a.Ngay_mo_so.year == b.Ngay_mo_so.year){
        if (a.Ngay_mo_so.month < b.Ngay_mo_so.month){
            return 1;
        }else if (a.Ngay_mo_so.month == b.Ngay_mo_so.month){
            if (a.Ngay_mo_so.day <= b.Ngay_mo_so.day){
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Updates the provided `Date` object with the current date.
 * The function retrieves the current date from the system clock and sets the `day`, `month`,
 * and `year` attributes of the `Date` object accordingly.
 *
 * @param date Reference to a `Date` object that will be updated with the current date.
 */

void today(Date &date){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date.day = ltm->tm_mday;
    date.month = 1 + ltm->tm_mon;
    date.year = 1900 + ltm->tm_year;
}

/**
 * Calculates the interest amount for a savings account.
 * The interest amount is calculated based on the type of savings account, the amount deposited,
 * and the interest rate.
 * 
 * @param stk The savings account for which the interest amount is to be calculated.
 * @param tienrut The amount to be withdrawn from the savings account.
 * @param rate The interest rate for the savings account.
 * @return The interest amount for the savings account.
 */

long double calcTienLai(SoTietKiem stk, double tienrut, double rate){
    Date ngayruttien;
    today(ngayruttien);
    int DayinYear = 365;
    int thoigian =  (ngayruttien.year - stk.Ngay_mo_so.year) * DayinYear + 
    (ngayruttien.month - stk.Ngay_mo_so.month) * 30 + 
    (ngayruttien.day - stk.Ngay_mo_so.day);
    long double tienlai = 0;
    tienlai = tienrut * (rate/100) * (thoigian / double(365));
    return tienlai;
}

/**
 * Withdraws money from a savings account.
 * The function prompts the user to enter the amount to be withdrawn and then updates the balance
 * of the savings account accordingly. If the withdrawal amount exceeds the balance, the function
 * displays an error message.
 * 
 * @param stk The savings account from which money is to be withdrawn.
 */

void rutTienMain(SoTietKiem &stk){
    Date ngayruttien;
    today(ngayruttien);
    int DayinYear = 365;
    int thoigian =  (ngayruttien.year - stk.Ngay_mo_so.year) * DayinYear + 
    (ngayruttien.month - stk.Ngay_mo_so.month) * 30 + 
    (ngayruttien.day - stk.Ngay_mo_so.day);
    double rate = stk.lai_suat;
    if (thoigian < 180){
        cout << "Ban dang rut tien truoc han! Lai suat se duoc dieu chinh xuong 0.5%/năm.\n";
        rate = 0.5;
    }
    int choice = 0, ok = 1, innerok = 1;
    stk.tien_lai = calcTienLai(stk, stk.So_tien_gui,rate);
    long double tien_rut, max_tien_rut;
    while(ok){
        cout << "--------------------------\n";
        cout << "1. Rut toan bo so tien." << endl;
        cout << "2. Rut mot phan so tien." << endl;
        cout << "3. Thoat." << endl;
        max_tien_rut = stk.So_tien_gui + stk.tien_lai;
        cout << "So tien hien co: " << fixed << setprecision(2) << max_tien_rut << endl;
        cout << "--------------------------\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        
        switch (choice){
            case 1:
                cout << "Ban da rut toan bo so tien: " << fixed << setprecision(2) << stk.So_tien_gui + stk.tien_lai << endl;
                stk.So_tien_gui = 0;
                stk.tien_lai = 0;
                break;
            case 2:
                innerok = 1;
                while(innerok){
                    cout << "Nhap so tien can rut: ";
                    cin >> tien_rut;
                    if (tien_rut > max_tien_rut){
                        cout << "Ban khong co du tien Vui long nhap lai.\n";
                    }else{
                        cout << "Ban da rut so tien: " << fixed << setprecision(2) << tien_rut << endl;
                        if (tien_rut > stk.tien_lai){
                            tien_rut -= stk.tien_lai;
                            stk.tien_lai = 0;
                        }
                        stk.So_tien_gui -= tien_rut;
                        innerok = 0;
                    }
                }
                
                break;
            case 3:
                ok = 0;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    }
}

/**
 * Compares two dates.
 * 
 * @param a The first date.
 * @param b The second date.
 * @return true if the first date is earlier than the second, false otherwise.
 */

bool sosanh2date(Date a, Date b){
    if (a.year < b.year){
        return 1;
    }else if (a.year == b.year){
        if (a.month < b.month){
            return 1;
        }else if (a.month == b.month){
            if (a.day <= b.day){
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Sorts the array of savings accounts based on the amount deposited.
 * 
 * @param stk The array of savings accounts.
 * @param n The number of savings accounts in the array.
 */

bool sosanhtien2stk(SoTietKiem a, SoTietKiem b){
    if (a.So_tien_gui > b.So_tien_gui){
        return 1;
    }
    return 0;
}

/**
 * Sorts the array of savings accounts based on the opening date.
 * 
 * @param stk The array of savings accounts.
 * @param n The number of savings accounts in the array.
 */

void sortMain(SoTietKiem stk[], int n){
    int choice = 0, ok = 1;
    while(ok){
        cout << "1. Sap xep danh sach theo so tien giam dan." << endl;
        cout << "2. Sap xep danh sach theo ngay mo so tang dan." << endl;
        cout << "3. Thoat." << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Danh sach sau khi sap xep theo so tien giam dan: " << endl;
                sort(stk, stk + n, sosanhtien2stk);
                for (int i = 0; i < n; i++){
                    HienThiThongTin(stk[i]);
                }
                break;
            case 2:
                cout << "Danh sach sau khi sap xep theo ngay mo so tang dan: " << endl;
                sort(stk, stk + n, sosanhngay2stk);
                for (int i = 0; i < n; i++){
                    HienThiThongTin(stk[i]);
                }
                break;
            case 3:
                ok = 0;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    }
}

/**
 * Displays the information of a savings account that was opened within a given period.
 * 
 * @param stk The savings account to be displayed.
 */

void LietKeMain(SoTietKiem stk[], int n){
    Date ngaybatdau, ngayketthuc;
    cout << "Nhap ngay bat dau (dd mm yyyy): ";
    cin >> ngaybatdau.day >> ngaybatdau.month >> ngaybatdau.year;
    cout << "Nhap ngay ket thuc (dd mm yyyy): ";
    cin >> ngayketthuc.day >> ngayketthuc.month >> ngayketthuc.year;
    for (int i = 0; i < n; i++){
        if (sosanh2date(ngaybatdau, stk[i].Ngay_mo_so) && sosanh2date(stk[i].Ngay_mo_so, ngayketthuc)){
            HienThiThongTin(stk[i]);
        }
    }
}

/**
 * Prompts the user to enter information for a savings account.
 * 
 * @param stk The savings account to be filled with information.
 */

void Nhap(SoTietKiem &stk){
    do {
        cout << "Nhap ma so: ";
        getline(cin, stk.MaSo);
        if (!isValidCode(stk.MaSo)) {
            cout << "Ma so khong hop le! Vui long nhap lai.\n";
        }
    }while(!isValidCode(stk.MaSo));

    do {
        cout << "Nhap loai tiet kiem: ";
        getline(cin, stk.Loai_tiet_kiem);
        if (!isValidLoaiTietKiem(stk.Loai_tiet_kiem)) {
            cout << "Loai tiet kiem khong hop le! Vui long nhap lai.\n";
        }
        if (stk.Loai_tiet_kiem == "Ngan han"){
            stk.lai_suat = lai_suat_ngan_han;
        }else if (stk.Loai_tiet_kiem == "Dai han"){
            stk.lai_suat = lai_suat_dai_han;
        }else if (stk.Loai_tiet_kiem == "Khong ky han"){
            stk.lai_suat = lai_suat_khong_ky_han;
        }
    }while(!isValidLoaiTietKiem(stk.Loai_tiet_kiem));

    do {
        cout << "Nhap ho ten khach hang: ";
        getline(cin, stk.Ho_ten_khach_hang);
        if (!isValidName(stk.Ho_ten_khach_hang)) {
            cout << "Ho ten khach hang khong hop le! Vui long nhap lai.\n";
        }
    }while(!isValidName(stk.Ho_ten_khach_hang));

    do {
        cout << "Nhap CMND: ";
        getline(cin, stk.CMND);
        if (!isValidCMND(stk.CMND)) {
            cout << "CMND khong hop le! Vui long nhap lai.\n";
        }
    }while(!isValidCMND(stk.CMND));

    do {
        cout << "Nhap ngay mo so (dd mm yyyy): ";
        cin >> stk.Ngay_mo_so.day >> stk.Ngay_mo_so.month >> stk.Ngay_mo_so.year;
        if (!verify_input(stk.Ngay_mo_so.day, stk.Ngay_mo_so.month, stk.Ngay_mo_so.year)) {
            cout << "Ngay mo so khong hop le! Vui long nhap lai.\n";
        }
    }while(!verify_input(stk.Ngay_mo_so.day, stk.Ngay_mo_so.month, stk.Ngay_mo_so.year));

    do {
        cout << "Nhap so tien gui: ";
        cin >> stk.So_tien_gui;
        if (stk.So_tien_gui <= 0) {
            cout << "So tien gui phai lon hon 0 Vui long nhap lai.\n";
        }
        stk.tien_lai = calcTienLai(stk, stk.So_tien_gui, stk.lai_suat);
    } while (stk.So_tien_gui <= 0);
    cin.ignore();
}

/**
 * Updates the interest rate for a savings account.
 * 
 * @param stk The savings account for which the interest rate is to be updated.
 * @param laisuat The new interest rate.
 */

void capnhatLaisuat(SoTietKiem &stk, double laisuat){
    stk.lai_suat = laisuat;
    cout << "Da cap nhat lai suat cho so tiet kiem: " << stk.MaSo << endl;
    stk.tien_lai = calcTienLai(stk, stk.So_tien_gui, stk.lai_suat);
    cout << "So tien lai hien tai: " << fixed << setprecision(2) << stk.tien_lai << endl;
}

/**
 * The main function.
 * 
 * The program prompts the user to enter information for a number of savings accounts.
 * It then provides options to:
 * - Search for a savings account by account code or ID card number.
 * - List the savings accounts opened within a given period.
 * - Sort the list of savings accounts based on the amount deposited or the opening date.
 * - Update the interest rate for a savings account.
 * - Calculate the current interest amount for a savings account.
 * - Withdraw money from a savings account.
 * - Exit the program.
 * 
 * The program runs until the user chooses to exit.
 * 
 * @return 0 if the program runs successfully.
 */

int main(){
    int n;
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    cin.ignore();
    SoTietKiem stk[n];
    for (int i = 0; i < n; i++){
        Nhap(stk[i]);
    }

    int choice = 0, ok = 1;
    while(ok){
        cout << "1. Tim kiem so tiet kiem theo CMND hoac ma so." << endl;
        cout << "2. Liet ke cac so tiet kiem duoc mo trong mot khoang thoi gian." << endl;
        cout << "3. Sap xep danh sach so tiet kiem." << endl;
        cout << "4. Cap nhat lai suat." << endl;
        cout << "5. Tinh tien lai hien tai." << endl;
        cout << "6. Rut tien." << endl;
        cout << "7. Thoat." << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        string tukhoa;
        string masotietkiem;
        long double laisuat;
        int found = 0;
        switch (choice){
            case 1:
                cout << "Nhap thong tin cua so tiet kiem can tim: ";
                cin.ignore();
                getline(cin, tukhoa);
                TimKiemTheoMaSo(stk, tukhoa, n);
                break;
            case 2:
                LietKeMain(stk, n);
                break;
            case 3:
                sortMain(stk, n);
                break;
            case 4:
                found = 0;
                cin.ignore();
                do {
                    cout << "Nhap ma so tiet kiem: ";
                    getline(cin, masotietkiem);
                    if (!isValidCode(masotietkiem)) {
                        cout << "Ma so khong hop le! Vui long nhap lai.\n";
                    }
                }while(!isValidCode(masotietkiem));
                cout << "Nhap lai suat moi: ";
                cin >> laisuat;
                for (int i = 0; i < n; i++){
                    if (stk[i].MaSo == masotietkiem){
                        capnhatLaisuat(stk[i], laisuat);
                        found = 1;
                        break;
                    }
                }
                if (!found){
                    cout << "Khong tim thay so tiet kiem co ma so: " << masotietkiem << endl;
                }
                break;
            case 5:
                found = 0;
                cin.ignore();
                do {
                    cout << "Nhap ma so tiet kiem: ";
                    getline(cin, masotietkiem);
                    if (!isValidCode(masotietkiem)) {
                        cout << "Ma so khong hop le! Vui long nhap lai.\n";
                    }
                }while(!isValidCode(masotietkiem));
                for (int i = 0; i < n; i++){
                    if (stk[i].MaSo == masotietkiem){
                        cout << "So tien lai hien tai: " << stk[i].tien_lai << endl;
                        found = 1;
                        break;
                    }
                }
                if (!found){
                    cout << "Khong tim thay so tiet kiem co ma so: " << masotietkiem << endl;
                }
                break;
            case 6:
                found = 0;
                cin.ignore();
                do {
                    cout << "Nhap ma so tiet kiem: ";
                    getline(cin, masotietkiem);
                    if (!isValidCode(masotietkiem)) {
                        cout << "Ma so khong hop le! Vui long nhap lai.\n";
                    }
                }while(!isValidCode(masotietkiem));
                for (int i = 0; i < n; i++){
                    if (stk[i].MaSo == masotietkiem){
                        rutTienMain(stk[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found){
                    cout << "Khong tim thay so tiet kiem co ma so: " << masotietkiem << endl;
                }
                break;
            case 7:
                ok = 0;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    }
    

    return 0;
}