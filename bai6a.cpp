#include <bits/stdc++.h>

using namespace std;

int soLuongA, soLuongB;

/**
 * Computes the Longest Prefix Suffix (LPS) array used in the KMP pattern matching algorithm.
 * The LPS array helps to avoid redundant comparisons by storing lengths of proper prefixes
 * that are also suffixes.
 *
 * @param A The pattern array for which the LPS array is to be computed.
 * @return A vector containing the LPS values for the given pattern.
 */
vector<int> tinhMangLPS(const vector<int>& A) {
    int doDai = 0;
    int i = 1;
    vector<int> lps(soLuongA, 0);

    while (i < soLuongA) {
        if (A[i] == A[doDai]) {
            doDai++;
            lps[i] = doDai;
            i++;
        } else {
            if (doDai != 0) {
                doDai = lps[doDai - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

/**
 * Counts the occurrences of array A as a contiguous subarray in array B using the KMP algorithm.
 * The function returns the number of times A appears in B, as well as the starting indices of all occurrences.
 *
 * @param A The pattern array to be found in array B.
 * @param B The target array in which the occurrences of A are to be found.
 * @return A pair containing the count of occurrences and a vector of starting indices of each occurrence.
 */
vector<int> timKiemKMP(const vector<int>& A, const vector<int>& B) {
    vector<int> ketQua;

    vector<int> lps = tinhMangLPS(A);
    int i = 0, j = 0; 

    while (j < soLuongB) {
        if (A[i] == B[j]) {
            i++;
            j++;

            if (i == soLuongA) {
                ketQua.push_back(j - i);
                i = lps[i - 1];
            }   
        }
        else {
            if (i != 0) {
                i = lps[i - 1];
            } else {
                j++;
            }
        }
    }

    return ketQua;
}

/**
 * The main function that reads input from the user, finds the occurrences of array A in array B,
 * and prints the results.
 *
 * @return 0 on successful execution.
 */
int main() {
    cout << "Nhap so luong phan tu cua hai mang A va B: ";
    cin >> soLuongA >> soLuongB;

    vector<int> A(soLuongA + 1), B(soLuongB + 1);
    cout << "Nhap cac phan tu cua mang A: ";
    for (int i = 0; i < soLuongA; ++i) {
        cin >> A[i];
    }

    cout << "Nhap cac phan tu cua mang B: ";
    for (int i = 0; i < soLuongB; ++i) {
        cin >> B[i];
    }

    vector<int> ketQua = timKiemKMP(A, B);

    cout << "So lan xuat hien cua A trong B la: " << ketQua.size() << '\n';
    cout << "Vi tri xuat hien cua A: ";
    for (int viTri : ketQua) {
        cout << viTri << " ";
    }
    cout << '\n';

    return 0;
}
