/*
    use 1 array - in index i save the probability of winning of the first draw player with picking stones.
    with the initial number of stones n, if after the first draw, with the remaining number of stones player 2 can win, 
    then in that case player 1 loses, and vice versa
*/
#include <stdio.h>
#include <iostream>

using namespace std;

bool stones[10001]; //stones[i] : check if the first draw wins with initial number of stones = i
                    // if stones[i] = true -> first player win
                    // if stones[i] = false -> second player win
int num_pick_stones[51];

int findwinner(bool stones[], int num_pick_stones[], int n, int m) {
    for (int i = 1; i <= n; i++) {
        stones[i] = false;
        for (int j = 0; j < m; j++) {
            if ((i-num_pick_stones[j] > 0) && (stones[i-num_pick_stones[j]] == false)) {
                stones[i] = true;
            }
        }
    }
    if (stones[n] == true) 
        return 1;
    else 
        return 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> num_pick_stones[i];
    }
    for (int i = 0; i <= n; i++) {
        stones[i] = i;
    }
    cout << findwinner(stones, num_pick_stones, n, m);
    return 0;
}