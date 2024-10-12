#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> 

using namespace std;

/**
 * Struct to store information of a student.
 * The information includes the student's name, scores in Mathematics, Literature, and Foreign Language,
 * the average score, and the classification of the student.
 */

struct HocSinh{
    string Hoten;
    double DiemToan;
    double DiemVan;
    double DiemNgoaiNgu;
    double DiemTB;
    string Phanloai;
};

/**
 * Checks if a given string is a valid name.
 * A valid name contains only alphabetic characters and has a length between 2 and 50 characters.
 * 
 * @param name The string to be checked.
 * @return true if the string is a valid name, false otherwise.
 */

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

/**
 * Calculates the average score of a student.
 * The average score is calculated as the sum of the scores in Mathematics (multiplied by 2), Literature, and Foreign Language, divided by 4.
 * 
 * @param hs The student for whom the average score is to be calculated.
 * @return The average score of the student.
 */

double TinhDiemTB(HocSinh &hs){
    return (hs.DiemToan * 2 + hs.DiemVan + hs.DiemNgoaiNgu) / 4;
}

/**
 * Classifies a student based on their average score.
 * The classification is as follows:
 * - "Xuat sac" for students with an average score of 9 or higher.
 * - "Gioi" for students with an average score between 8 and 8.9.
 * - "Kha" for students with an average score between 6.5 and 7.9.
 * - "Trung binh" for students with an average score between 5 and 6.4.
 * - "Yeu" for students with an average score below 5.
 * 
 * @param hs The student to be classified.
 * @return The classification of the student.
 */

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
/**
 * Displays the information of a student.
 * 
 * @param hs The student whose information is to be displayed.
 */

void HienThiThongTin(HocSinh hs){
    cout << "--------------------------\n";
    cout << "Ho ten: " << hs.Hoten << endl;
    cout << "Diem toan: " << hs.DiemToan << endl;
    cout << "Diem van: " << hs.DiemVan << endl;
    cout << "Diem ngoai ngu: " << hs.DiemNgoaiNgu << endl;
    cout << "Diem trung binh: " << hs.DiemTB << endl;
    cout << "Phan loai: " << hs.Phanloai << endl;
    cout << "--------------------------\n";
}

/**
 * Finds the student with the lowest score in Mathematics.
 * 
 * @param hs The array of students.
 */

void DanhSachHocSinhDiemToanthapnhat(HocSinh hs[]){
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

/**
 * Finds the student with the highest average score.
 * 
 * @param hs The array of students.
 */
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
 * Searches for a student by name.
 * 
 * @param hs The array of students.
 * @param tuKhoa The name to search for.
 */
void TimKiemTheoTen(HocSinh hs[], string tuKhoa) {
    bool found = false;
    string tuKhoaLower = toLower(tuKhoa);
    for (int i = 0; i < 3; i++) {
        string hotenLower = toLower(hs[i].Hoten);
        if (hotenLower.find(tuKhoaLower) != string::npos) {
            cout << "Tim thay hoc sinh: " << hs[i].Hoten << endl;
            HienThiThongTin(hs[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay hoc sinh nao voi ten \"" << tuKhoa << "\"\n";
    }
}

/**
 * Prompts the user to enter information for a student.
 * 
 * @param hs The student to be filled with information.
 */
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


/**
 * Main function to demonstrate the student management system.
 * The program prompts the user to enter information for three students.
 * It then displays the information of each student and provides options to:
 * - Find the student with the highest average score.
 * - Find the student with the lowest score in Mathematics.
 * - Search for a student by name.
 * - Exit the program.
 * 
 * @return 0 on successful execution.
 */

int main() {
    HocSinh hs[3];
    for (int i = 0; i < 3; i++){
        cout << "Nhap thong tin hoc sinh thu " << i+1 << endl;
        Nhap(hs[i]);
    }
    for (int i = 0; i < 3; i++){
        cout << "Thong tin hoc sinh thu " << i+1 << endl;
        HienThiThongTin(hs[i]);
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
                DanhSachHocSinhDiemToanthapnhat(hs);
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
