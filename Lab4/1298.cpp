#include<iostream>
#include<stdio.h>
#include <cstring>
#include <vector>
using namespace std;
 
int table[8][8];
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int num_moves = 0;
int n;

vector<char> result;

void printresult() {
    for (int i = 0; i < result.size(); i+=2) {
        cout << result[i] << result[i+1] << endl;
    } 
}

bool checkMove (int x, int y, int x1, int y1) {
    if (x + x1 >= 0 && x + x1 < n && y + y1 >= 0 && y + y1 < n && table[x + x1][y + y1] == 0) {
        return true;
    }
    return false;
}

void move(int x, int y) {   //x,y : starting position
    num_moves++;
    table[x][y] = 1;
    result.push_back((char)(y+'a'));
    result.push_back((char)(x+1+'0'));
    for (int i = 0; i < 8; i++)    {
        if (num_moves == n * n) {
            printresult();
            exit(0);
        }
        if (checkMove(x,y,X[i],Y[i])) {
            move(x + X[i], y + Y[i]);
        }
           
    }
    num_moves--;
    result.pop_back();
    result.pop_back();
    table[x][y] = 0;
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; i <= n; j++) {
            table[i][j] = 0;
        }
        
    }
    move(0, 0);
    cout << "IMPOSSIBLE";
}