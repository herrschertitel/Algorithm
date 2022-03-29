#include <iostream>

using namespace std;

void swap(int &a,int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

int main() {
    int n;
    int a[100], b[100], c[100], d[100];
    cin >> n;
    for (int i=0; i < n ; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(b[j] < b[i]){
                swap(b[i],b[j]);
                swap(a[i],a[j]);     
            }
        }
    }
    // cout << "sau khi sap xep:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " " << b[i] << endl;
    // }
    c[0] = a[0];
    d[0] = b[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        // cout << "so sanh: " << a[i] << " " << d[i-1] << endl;
        if (a[i] >= d[count-1]) {
            c[count] = a[i];
            d[count] = b[i];
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << c[i] << " " << d[i] << endl;
    }
    return 0;
}