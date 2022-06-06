#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr1[], int arr2[], int low, int high)
{
    int pivot = arr2[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr2[j] > pivot)
        {
            i++; // increment index of smaller element
            swap(&arr1[i], &arr1[j]);
            swap(&arr2[i], &arr2[j]);
        }
    }
    swap(&arr1[i + 1], &arr1[high]);
    swap(&arr2[i + 1], &arr2[high]);
    return (i + 1);
}
 

void quickSort(int arr1[],int arr2[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr1, arr2, low, high);
 
        // Separately sort elements before partition and after partition
        quickSort(arr1, arr2, low, pi - 1);
        quickSort(arr1, arr2, pi + 1, high);
    }
}

int depth[500];
vector<int> parent[500];

int main() {
    int l_point[500], r_point[500], leng_sigs[500], id_sigs[500];
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> l_point[i] >> r_point[i];
        leng_sigs[i] = r_point[i] - l_point[i];
        id_sigs[i] = i;
    }
    quickSort(id_sigs,leng_sigs,1,N);
    /*for (int i = 1; i <= N; i++) {
        cout << id_sigs[i] << ": ";
        cout << l_point[id_sigs[i]] << " " << r_point[id_sigs[i]] << endl;
    }*/
    for (int i = 1; i <= N; i++) {
        depth[i] = 1;
        parent[i].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (l_point[id_sigs[i]] > l_point[id_sigs[j]] && r_point[id_sigs[i]] < r_point[id_sigs[j]]) {
                if (depth[id_sigs[j]]+1 > depth[id_sigs[i]] ) {
                    depth[id_sigs[i]] = depth[id_sigs[j]]+1;
                    while (parent[id_sigs[i]].size()>0){
                        parent[id_sigs[i]].pop_back();
                    }
                    for (int k = 0; k < parent[id_sigs[j]].size(); k++) {
                        parent[id_sigs[i]].push_back(parent[id_sigs[j]][k]);
                    }
                    parent[id_sigs[i]].push_back(id_sigs[i]);
                }
            }
        }
    }
    int max = 0, index;
    for (int i = 1; i<= N; i++) {
        if (depth[i] > max) {
            max = depth[i];
            index = i;
        }
    }
    cout << max << endl;
    for (int i = parent[index].size() - 1; i >= 0 ; i--) {
        cout << parent[index][i] << " ";
    }
    return 0;
}