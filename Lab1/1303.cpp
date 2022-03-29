#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

void merge(int arr1[], int arr2[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L1[n1], R1[n2], L2[n1], R2[n2];
    for (i = 0; i < n1; i++)
    {
        L1[i] = arr1[l + i];
        L2[i] = arr2[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R1[j] = arr1[m + 1 + j];
        R2[j] = arr2[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L2[i] >= R2[j])
        {
            arr1[k] = L1[i];
            arr2[k] = L2[i];
            i++;
        }
        else
        {
            arr1[k] = R1[j];
            arr2[k] = R2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr1[k] = L1[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr1[k] = R1[j];
        arr2[k] = R2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr1[], int arr2[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr1, arr2, l, m);
        mergeSort(arr1, arr2, m + 1, r);
        merge(arr1, arr2, l, m, r);
    }
}

int main()
{
    int m, c[100001];
    int l[100001], r[100001];
    int lout[100001], rout[100001];
    cin >> m;
    int x, y, k = 0, cont = 0, num = 0, p = 0, flag = 0, ans = 0, i;
    while (scanf("%d%d", &x, &y) && !(x == 0 && y == 0))
    {
        l[k] = x;
        r[k] = y;
        k++;
    }
    mergeSort(l, r, 0, k - 1);
    int end = 0;
    int check = 1;
    int count = 0;
    while (end < m && check)
    {
        check = 0;
        for (int i = 0; i < k; i++)
        {
            if (l[i] <= end && end < r[i])
            {
                end = r[i];
                check = 1;
                // cout << "Р вЂќР С•Р В±Р В°Р Р†Р С‘РЎвЂљРЎРЉ: " << l[i] << " " << r[i] << endl;
                lout[count] = l[i];
                rout[count] = r[i];
                count++;
                break;
            }
        }
    }
    if (end < m)
    {
        cout << "No solution";
    }
    else
    {
        cout << count << endl;
        for (int i = 0; i < count; i++)
        {
            cout << lout[i] << " " << rout[i] << endl;
        }
    }
    return 0;
}