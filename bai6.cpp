#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 1e5;

int soLuongA, soLuongB;

/**
 * Computes the Longest Prefix Suffix (LPS) array for a given array.
 * 
 * @param A The array for which the LPS array is to be computed.
 * @param lps The array to store the LPS values.
 */

void tinhMangLPS(int A[], int lps[]) {
    int doDai = 0; 
    int i = 1;   

    lps[0] = 0; 

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
}

/**
 * Searches for occurrences of array A in array B using the Knuth-Morris-Pratt (KMP) algorithm.
 * 
 * @param A The array to be searched for.
 * @param B The array to be searched in.
 * @param viTri The array to store the positions of occurrences.
 * @return The number of occurrences of A in B.
 */

int timKiemKMP(int A[], int B[], int viTri[]) {
    int lps[MAX_SIZE];
    tinhMangLPS(A, lps);

    int count = 0; 
    int i = 0; 
    int j = 0;   

    while (j < soLuongB) {
        if (A[i] == B[j]) {
            i++;
            j++;

            if (i == soLuongA) {
                viTri[count] = j - i;
                count++;
                i = lps[i - 1];
            }
        } else {
            if (i != 0) {
                i = lps[i - 1];
            } else {
                j++;
            }
        }
    }

    return count; 
}

/**
 * Main function to search for occurrences of array A in array B.
 * The program prompts the user to input the elements of arrays A and B.
 * It then calls the `timKiemKMP` function to find the occurrences of A in B.
 * The number of occurrences and the positions are printed to the console.
 * 
 * @return 0 on successful execution.
 */

int main() {
    cout << "Nhap so luong phan tu cua hai mang A va B: ";
    cin >> soLuongA >> soLuongB;

    int A[MAX_SIZE], B[MAX_SIZE], viTri[MAX_SIZE];

    cout << "Nhap cac phan tu cua mang A: ";
    for (int i = 0; i < soLuongA; ++i) {
        cin >> A[i];
    }

    cout << "Nhap cac phan tu cua mang B: ";
    for (int i = 0; i < soLuongB; ++i) {
        cin >> B[i];
    }

    int count = timKiemKMP(A, B, viTri);

    cout << "So lan xuat hien cua A trong B la: " << count << endl;
    cout << "Vi tri xuat hien cua A: ";
    for (int i = 0; i < count; ++i) {
        cout << viTri[i] << " ";
    }
    cout << endl;

    return 0;
}
