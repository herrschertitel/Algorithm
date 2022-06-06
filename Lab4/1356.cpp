/*
For the minimum number of primes that sum to a given number N, the primes must be as large as possible. Below are the observations for the above problem statement:

    Case 1. If the number is prime, then the minimum number of primes required to obtain the sum N is 1.
    Case 2: If a number is even, then it can be expressed as the sum of two primes according to Goldbach's conjecture for every even integer greater than 2. 
            Therefore, the minimum prime needed to obtain the sum N is 2.
    Case 3: If the number is odd:
                If (N-2) is a prime, then the minimum prime required to produce a given sum N is 2.
                Otherwise, the minimum prime required to obtain a given sum N is 3.
*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

bool checkPrime(int n) {
    if(n == 1)
        return false;
    int k = sqrt(n);
    for(int i = 2; i <= k; i++)
       if(n % i == 0)
           return false;
    return true;
}

int main() {
    int T, N;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        if (N < 4 || checkPrime(N))
            cout << N << endl;
        else if (N % 2 == 0) {
            if (checkPrime(N-2))
                cout << "2 " << N-2 << endl; 
            else {
                for(int k = 3; ; k += 2) {
                    if(checkPrime(k) && checkPrime(N-k)) {
                        cout << k << " " << N-k << endl;
                        break;
                    }
                }
            }
        }
        else {
            if (checkPrime(N-2))
                cout << "2 " << N-2 << endl;
            else {
                N = N - 3;
                for(int k = N-3; ; k -= 2) {
                    if(checkPrime(k) && checkPrime(N-k)) {
                        cout << "3 " << k << " " << N-k << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}