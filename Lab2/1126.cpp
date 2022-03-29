#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, value;
    int arr[25000];
    vector<int> res;
    cin >> M;
    int count = 0;
    do {
        cin >> value;
        if (value == -1) break;
        count++;
        arr[(count-1)%M] = value;
        if (count >= M) {
            int max = 0;
            for (int i = 0; i < M; i++) {
                if (max < arr[i])
                    max = arr[i];
            }
            res.push_back(max);
        }
    }
    while (value!=-1);
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << endl;
    return 0;
}