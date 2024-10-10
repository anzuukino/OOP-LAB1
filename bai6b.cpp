#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> 

using namespace std;

struct HocSinh{
    string Hoten;
    double DiemToan;
    double DiemVan;
    double DiemNgoaiNgu;
    double DiemTB;
    string Phanloai;
};

bool isValidName(const string &name) {
    if (name.length() < 2 || name.length() > 50) {
        return false;
    }
    for (char ch : name) {
        if (isdigit(ch)) {
            return false;
        }
    }
    return true;
}

double TinhDiemTB(HocSinh &hs){
    return (hs.DiemToan * 2 + hs.DiemVan + hs.DiemNgoaiNgu) / 4;
}

string PhanLoai(HocSinh &hs){
    if (hs.DiemTB >= 9){
        return "Xuat sac";
    }
    else if (hs.DiemTB >= 8){
        return "Gioi";
    }
    else if (hs.DiemTB >= 6.5){
        return "Kha";
    }
    else if (hs.DiemTB >= 5){
        return "Trung binh";
    }
    else{
        return "Yeu";
    }
}
void DanhSachHocSinhToanthapnhat(HocSinh hs[]){
    double Min = hs[0].DiemToan;
    int index = 0;
    for (int i = 1; i < 3; i++){
        if (hs[i].DiemToan < Min){
            Min = hs[i].DiemToan;
            index = i;
        }
    }
    cout << "Hoc sinh co diem toan thap nhat la: " << hs[index].Hoten << endl;
    cout << "Diem toan: " << hs[index].DiemToan << endl;
}
void timHocSinhgioinhat(HocSinh hs[]){
    double Max = hs[0].DiemTB;
    int index = 0;
    for (int i = 1; i < 3; i++){
        if (hs[i].DiemTB > Max){
            Max = hs[i].DiemTB;
            index = i;
        }
    }
    cout << "Hoc sinh co diem trung binh cao nhat la: " << hs[index].Hoten << endl;
    cout << "Diem trung binh: " << hs[index].DiemTB << endl;
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void TimKiemTheoTen(HocSinh hs[], string tuKhoa) {
    bool found = false;
    string tuKhoaLower = toLower(tuKhoa);
    for (int i = 0; i < 3; i++) {
        string hotenLower = toLower(hs[i].Hoten);
        if (hotenLower.find(tuKhoaLower) != string::npos) {
            cout << "Tim thay hoc sinh: " << hs[i].Hoten << " - Diem trung binh: " << hs[i].DiemTB << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay hoc sinh nao voi ten \"" << tuKhoa << "\"\n";
    }
}

void Nhap(HocSinh &hs){
    do {
        cout << "Nhap ho ten (khong chua so, do dai tu 2 den 50 ky tu): ";
        getline(cin, hs.Hoten);
        if (!isValidName(hs.Hoten)) {
            cout << "Ho ten khong hop le! Vui long nhap lai.\n";
        }
    } while (!isValidName(hs.Hoten));

    do {
        cout << "Nhap diem toan: ";
        cin >> hs.DiemToan;
        if (hs.DiemToan < 0 || hs.DiemToan > 10){
            cout << "Diem toan khong hop le. Vui long nhap lai." << endl;
        }
    }while(hs.DiemToan < 0 || hs.DiemToan > 10);
    
    do {
        cout << "Nhap diem van: ";
        cin >> hs.DiemVan;
        if (hs.DiemVan < 0 || hs.DiemVan > 10){
            cout << "Diem van khong hop le. Vui long nhap lai." << endl;
        }
    }while(hs.DiemVan < 0 || hs.DiemVan > 10);

    do {
        cout << "Nhap diem ngoai ngu: ";
        cin >> hs.DiemNgoaiNgu;
        if (hs.DiemNgoaiNgu < 0 || hs.DiemNgoaiNgu > 10){
            cout << "Diem ngoai ngu khong hop le. Vui long nhap lai." << endl;
        }
    }while(hs.DiemNgoaiNgu < 0 || hs.DiemNgoaiNgu > 10);
    cin.ignore();
    hs.DiemTB = TinhDiemTB(hs);
    hs.Phanloai = PhanLoai(hs);
}

int main() {
    HocSinh hs[3];
    for (int i = 0; i < 3; i++){
        cout << "Nhap thong tin hoc sinh thu " << i+1 << endl;
        Nhap(hs[i]);
    }
    for (int i = 0; i < 3; i++){
        cout << "Thong tin hoc sinh thu " << i+1 << endl;
        cout << "Ho ten: " << hs[i].Hoten << endl;
        cout << "Diem toan: " << hs[i].DiemToan << endl;
        cout << "Diem van: " << hs[i].DiemVan << endl;
        cout << "Diem ngoai ngu: " << hs[i].DiemNgoaiNgu << endl;
        cout << "Diem trung binh: " << hs[i].DiemTB << endl;
        cout << "Phan loai: " << hs[i].Phanloai << endl;
    }
    int choice = 0, ok = 1;
    while(ok){
        cout << "1. Tim hoc sinh co diem trung binh cao nhat." << endl;
        cout << "2. Xuat hoc sinh co diem toan thap nhat." << endl;
        cout << "3. Tim kiem hoc sinh theo ten." << endl;
        cout << "4. Ket thuc chuong trinh." << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        string tukhoa;
        switch (choice){
            case 1:
                timHocSinhgioinhat(hs);
                break;
            case 2:
                DanhSachHocSinhToanthapnhat(hs);
                break;
            case 3:
                cout << "Nhap ten hoc sinh can tim: ";
                cin.ignore();
                getline(cin, tukhoa);
                TimKiemTheoTen(hs, tukhoa);
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
