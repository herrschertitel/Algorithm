#include <iostream>
#include<stdio.h>
#include <math.h>

using namespace std;

int main() {
	int n, ip[100000];
	cin >> n;
	int top = 0, dem = 1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (ip[top] != a & dem < n) {
			top++;
			ip[top] = dem;
			dem++;
		}
		if (ip[top] == a)
			top--;
	}
	if (top == 0)
		cout << "Not a proof";
	else cout << "Cheater";

	return 0;
}