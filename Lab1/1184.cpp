#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	int n, k;
	double arr[10000];
	cin >> n >> k;
	double m, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	/*cout << n << ' ' << k << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;*/
	//cout << endl << sum << endl;
	m = sum / k;
	//cout << m << endl;
	double l = 0, r = m;
	while (r-l > 1e-10) {
		double mid = (r + l) / 2;
		int dem = 0;
		for (int i = 0; i < n; i++) {
			dem+= (int)(arr[i] / mid);	
		}
		if (dem < k)
			r = mid;
		if (dem >= k)
			l = mid;
	} 
	printf("%.2lf\n", floor(r * 100) / 100);
	/*for (int i = 0; i < n; i++)
		cout << (int)(arr[i] / r) << ' ';
	cout << r;*/
	return 0;
}