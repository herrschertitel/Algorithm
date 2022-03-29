#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    float a0, an, c[3000], cumma = 0, a1;
    cin >> n;
    cin >> a0;
    cin >> an;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cumma = cumma + 2*(n+1-i)*c[i];
    }
    a1 = an + n * a0 - cumma;
    a1 = a1/(n+1);
    printf("%.2f", a1);
    return 0;
}