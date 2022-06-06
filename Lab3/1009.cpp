#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[17];
    a[1] = k - 1;
    a[2] = k * (k - 1);

    for (int i = 3; i <= n; i++) {
        a[i] = (k - 1) * (a[i - 1] + a[i - 2]);
    }

    cout << a[n] << endl;
    return 0;  
}