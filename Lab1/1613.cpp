#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

map<int, vector<int> > index;  // index[x] = vector() : array containing the index of the city with the number of train passengers equal to x

int binarySearch(vector<int> &a, int x, int y) { //function to check if an element in array a exists in the range [x, y]
    int l = 0, r = a.size()-1;
    while (r >= l) {
        int mid = l + (r-l)/2;
        if (a[mid] >= x && a[mid] <= y) {
            return 1;
        } 
        else if (a[mid] < x) {
                l = mid+1;
        }
        else if (a[mid] > y) {
            r = mid-1;
        }
    }
    return 0;
}

int main() {
    int n, q;
    cin >> n;
    string result = "";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        index[a].push_back(i);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        if (binarySearch(index[x],l-1,r-1)) result += '1';
        else result += '0';
    } 
    cout << result;
    return 0;
}