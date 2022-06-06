#include <stdio.h>
#include <iostream>

using namespace std;

int A[901][8101]; 
int B[901][8101];

int main () {
    for (int i = 0; i <= 900; i++) {
        for (int j = 0; j <= 8100; j++) {
            A[i][j] = 101;
        }
    }
    A[0][0] = 0;
    for (int i = 0; i <= 900; i++) {
        for (int j = i; j <= 8100; j++) {
            for (int k = 1; k <= 9; k++) {
                int f = k*k;
                if (i-k < 0 || j-f < 0) {
                    break;
                }
                else {
                    if (A[i][j] > A[i-k][j-f] + 1) {
                        A[i][j] = A[i-k][j-f] + 1;
                        B[i][j] = k;
                    }
                }
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        //cout << A[s1][s2] << endl;
        if (s1 > s2 || s1 > 900 || s2 > 8100) {
            cout << "No solution" << endl;
            continue;
        }
        else {
            if (A[s1][s2] == 101) {
                cout << "No solution" << endl;
            }
            else {
                int x = s1, y = s2;
                for (int j = 1; j <= A[s1][s2]; j++) {
                    int k = B[x][y];
                    cout << k;
                    x = x - k;
                    y = y - k* k;
                }
                cout << endl;
            }
        }
    }
    return 0;
}