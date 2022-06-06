#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int numdigits[901][8101];  //num_digits[i][i] : save the smallest number of digits whose sum = i and the square's sum = j
    /*
        max i = 9 * 100 = 900
        max j = 9^2 * 100 = 8100
    */
    int firstDigit[901][8101];  // 
    numdigits[1][1] = 1;
    /*for (int i = 0; i <= 900; i++) {
        for (int j = 0; j <= 8100; j++) {
            numdigits[i][j] = 101;
            firstDigit[i][j] = 0;
        }
    }*/
    //numdigits[0][0] = 0;
    cout << numdigits[1][1] << endl;
    /*for (int i = 0; i <= 900; i++) {
        for (int j = i; j <= 8100; j++) {
            for (int k = 1; k <= 9; k++) {
                if (((i - k) < 0) || ((j - k * k) < 0)) {
                    break;
                }
                if (num_digits[i][j] > num_digits[i - k][j - k * k] + 1) {
                    num_digits[i][j] = num_digits[i - k][j - k * k] + 1;
                    firstDigit[i][j] += num_digits[i][j]*10 + k;
                }
            }
        }
    }
    cout << num_digits[1][1] << endl;
    cout << firstDigit[12][9];*/
    return 0;
}