#include <iostream>
#include <string>
#include <regex>
#include <ctime>

using namespace std;

const double lai_suat_ngan_han = 0.03;
const double lai_suat_dai_han = 0.46;
const double lai_suat_khong_ky_han = 0.05;

struct Date{
    int day;
    int month;
    int year;
};

struct SoTietKiem{
    string MaSo;
    string Loai_tiet_kiem;
    string Ho_ten_khach_hang;
    string CMND;
    Date Ngay_mo_so;
    double So_tien_gui;
    double lai_suat;
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

bool isValidCode(const string &code) {
    regex pattern("^[A-Za-z0-9]{1,5}$");
    return regex_match(code, pattern);
}

bool isValidCMND(const string &code) {
    regex pattern("^(\\d{9}|\\d{12})$");
    return regex_match(code, pattern);
}

bool isValidName(const string &place) {
    regex pattern("^[A-Za-z\\s]{1,30}$");
    return regex_match(place, pattern);
}

bool isValidLoaiTietKiem(const string &loai) {
    regex pattern("^(Ngan han|Dai han|Khong ky han)$");
    return regex_match(loai, pattern);
}

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
    } while (stk.So_tien_gui <= 0);

}

void HienThiThongTin(SoTietKiem stk){
    cout << "--------------------------\n";
    cout << "Ma so: " << stk.MaSo << endl;
    cout << "Loai tiet kiem: " << stk.Loai_tiet_kiem << endl;
    cout << "Ho ten khach hang: " << stk.Ho_ten_khach_hang << endl;
    cout << "CMND: " << stk.CMND << endl;
    cout << "Ngay mo so: " << stk.Ngay_mo_so.day << "/" << stk.Ngay_mo_so.month << "/" << stk.Ngay_mo_so.year << endl;
    cout << "So tien gui: " << stk.So_tien_gui << endl;
    cout << "--------------------------\n";
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

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

// double TinhTienLai(SoTietKiem stk){
//     double tienlai = 0;
//     return tienlai;
// }

// double rutTien(SoTietKiem stk, double tienrut){
//     if (tienrut > stk.So_tien_gui){
//         cout << "So tien rut khong hop le! Vui long nhap lai.\n";
//     }else{
//         cout << "Ban da rut so tien: " << tienrut << endl;
//         stk.So_tien_gui -= tienrut;
//     }
//     return tienrut;
// }

void today(Date &date){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date.day = ltm->tm_mday;
    date.month = 1 + ltm->tm_mon;
    date.year = 1900 + ltm->tm_year;
}

// void rutTienMain(SoTietKiem &stk, double tienrut){
//     Date ngayruttien;
//     today(ngayruttien);
//     int thoigian = 12 * (ngayruttien.year - stk.Ngay_mo_so.year) + (ngayruttien.month - stk.Ngay_mo_so.month);
//     if (thoigian < 6 && stk.Loai_tiet_kiem != "Khong thoi han"){
//         cout << "Ban dang rut tien truoc han! Lãi suất được điều chỉnh xuống 0.5%/năm.\n";
//     }
//     int choice = 0, ok = 1;
//     while(ok){
//         cout << "1. Rut toan bo so tien." << endl;
//         cout << "2. Rut mot phan so tien." << endl;
//         cout << "3. Thoat." << endl;
//         cout << "Lua chon cua ban: ";
//         cin >> choice;
//         switch (choice){
//             case 1:
//                 double tien_rut = rutTien(stk, stk.So_tien_gui);
//                 cout << "Ban da rut toan bo so tien: " << tien_rut << endl;
//                 stk.So_tien_gui = 0;
//                 break;
//             case 2:
//                 double tien_rut;
//                 cout << "Nhap so tien can rut: ";
//                 cin >> tien_rut;
//                 double max_tien_rut = rutTien(stk,stk.So_tien_gui);
//                 cout << "So tien hien co: " << max_tien_rut << endl;
//                 if (tien_rut > max_tien_rut){
//                     cout << "Ban khong co du tien Vui long nhap lai.\n";
//                 }else{
//                     cout << "Ban da rut so tien: " << tien_rut << endl;
//                     stk.So_tien_gui -= tien_rut;
//                 }
//                 break;
//             case 3:
//                 ok = 0;
//                 break;
//             default:
//                 cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
//         }
//     }
// }

bool sosanhtien2stk(SoTietKiem a, SoTietKiem b){
    if (a.So_tien_gui > b.So_tien_gui){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    cin.ignore();
    SoTietKiem stk[n];
    for (int i = 0; i < n; i++){
        Nhap(stk[i]);
    }

    

    return 0;
}