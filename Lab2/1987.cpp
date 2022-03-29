#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef struct {
    int index;
    int l_point;
    int r_point;
} segment;

int main() {
    int m, n;
    vector <int> result;
    int a[100001], b[100001];
    cin >> n;
    segment listsegment[n];
    int max_r = 0;
    for (int i = 0; i < n; i++) {
        cin >> listsegment[i].l_point >> listsegment[i].r_point;
        if (listsegment[i].r_point > max_r) max_r = listsegment[i].r_point;
        listsegment[i].index = i+1;
    }
    int min_l = listsegment[0].l_point;
    int stack[100001], top = 0, j = 0; 
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        if (c < min_l || c > max_r) {
            result.push_back(-1);
        }
        else {
            while (c > listsegment[stack[top-1]-1].r_point && top > 0) {
                top--;
            }
            while (listsegment[j].l_point <= c && j < n) {
                if (listsegment[j].r_point >= c) {
                    stack[top] = j+1;
                    top++;
                }
                j++;
            }
            result.push_back(stack[top-1]);
        }
    }
    for (int i = 0; i < m; i++){
        cout << result[i] << endl;;
    }
    return 0;
}