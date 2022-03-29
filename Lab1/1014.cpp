#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int a[100];
    int count = 0;
    if (n == 1) cout << "1";
    else if (n ==0) cout << "10";
    else {
        int i = 9;
        while (i > 1) {
            if (n % i == 0) {
                a[count] = i;
                count++;
                n = n / i;
                i = 9;
            }
            else i--;
        }
        if (n == 1) {
            for (int j = count-1; j >=0; j--) {
                cout << a[j];
            }
        }
        else cout << "-1";
        }
    return 0;
}
