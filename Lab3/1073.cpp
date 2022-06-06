#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[60001]; 
    a[1] = 1;
    for (int i = 2; i <= N; i++) {
        int k = int(sqrt(i));
        if (k*k == i) {
            a[i] = 1;
        }
        else {
            a[i] = 60000;
            for (int j = 1; j <= k; j++) {
                if (a[i] > (a[i-j*j]+1))
                    a[i] = a[i-j*j] + 1;
            }
        }
    }
    cout << a[N];
    return 0;
}