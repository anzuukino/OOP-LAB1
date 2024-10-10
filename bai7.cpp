#include <iostream>
#include <string>
#include <regex>
#include <ctime>

using namespace std;
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

bool isValidFlightCode(const string &code) {
    regex pattern("^[A-Za-z0-9]{1,5}$");
    return regex_match(code, pattern);
}

bool isValidPlace(const string &place) {
    regex pattern("^[A-Za-z\\s]{1,20}$");
    return regex_match(place, pattern);
}

bool isValidTime(const string &time) {
    regex pattern("^([01][0-9]|2[0-3]):([0-5][0-9])$");
    return regex_match(time, pattern);
}

void parseTime(const string &time, Flight &flight) {
    flight.Giobay = stoi(time.substr(0, 2));
    flight.Phutbay = stoi(time.substr(3, 2));
}

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
void HienThiThongTinChuyenBay(const Flight &flight) {
    cout << "--------------------------\n";
    cout << "Ma chuyen bay: " << flight.MaChuyenBay << endl;
    cout << "Noi di: " << flight.Noidi << endl;
    cout << "Noi den: " << flight.Noiden << endl;
    cout << "Ngay bay: " << flight.Ngaybay << "/" << flight.Thangbay << "/" << flight.Nambay << endl;
    cout << "Gio bay: " << flight.Giobay << ":" << (flight.Phutbay < 10 ? "0" : "") << flight.Phutbay << endl;
    cout << "--------------------------\n";
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

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

void SoLuongChuyenBay(Flight flight[], int n, string noidi, string noiden){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (toLower(flight[i].Noidi) == toLower(noidi) && toLower(flight[i].Noiden) == toLower(noiden)){
            count++;
        }
    }
    cout << "So luong chuyen bay di tu " << noidi << " den " << noiden << " la: " << count << endl;
}

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