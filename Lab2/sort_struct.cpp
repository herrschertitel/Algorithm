#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int index;
    int l_point;
    int r_point;
    int length;
} segment;

void show_struct(segment array[], int n) {
    for (short i = 0; i < n; i++) {
      cout << array[i].index<<' '<< array[i].l_point<<' '
      << array[i].r_point<<' '<< array[i].length<<' '<< endl;
   }
    cout <<endl;
}

void merge(segment arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    segment L1[n1], R1[n2];
    for (i = 0; i < n1; i++) {
        L1[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R1[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i].length <= R1[j].length) {
            arr[k] = L1[i];
            i++;
        }
        else {
            arr[k] = R1[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R1[j];
        j++;
        k++;
    }
}
void mergeSort(segment arr[], int l, int r) {
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr,  l, m);
        mergeSort(arr,  m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    segment p[5] = {{1, 2, 10, 8},
                              {2, 2, 5, 3},
                              {3, 3, 10, 7},
                              {4, 4, 8, 4},
                              {5, 4, 6, 2}};
    mergeSort(p,0,4);
    show_struct(p,5);
    
}