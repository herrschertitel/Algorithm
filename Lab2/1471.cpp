#include <stdio.h>
#include <iostream>
#include<vector>
#include <queue>
using namespace std;

const int NMAX = 50000;
const int distance[NMAX][NMAX];

int distan[50001]; //distan[i] - distance between note i and root 0

void process3(int N, int T[100], int P[100][100]) {
  int i, j;

  // Khởi tạo
  for (i = 0; i < N; i++)
    for (j = 0; 1 << j < N; j++)
      P[i][j] = -1;

  // Khởi tạo cha thứ 2^0 = 1 của mỗi nút
  for (i = 0; i < N; i++)
    P[i][0] = T[i];

  // Quy hoạch động
  for (j = 1; 1 << j < N; j++)
    for (i = 0; i < N; i++)
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}

int dfs(int node, int parent[50001]) { // find deep of node i
  if (node == 0) {
    return 1;
  }
  else {
    return dfs(parent[node], parent) + 1;
  }
} 

  
int main() {
  int n, m;
  cin >> n;
  int parent[n],deep[n]; 
  /*
    - parent[n] : parent[i] - parent of i;
    - deep[n] : deep[i] - deep of node i
    - destance [n][n] : destance[i][j] - distance between node i and j
  */
  parent [0] = 0;
  for (int i = 1; i < n; i++) {
    parent[i] = -1;
  }
  for (int i = 0; i < n-1; i++) {
    int a,b,c;  
    cin >> a >> b >> c;
    if (parent[a] == -1) parent[a] = b; 
    else parent[b] = a;
    distance[a][b] = c; 
    distance[b][a] = c;
  }
  // for (int i = 0; i < n; i++) {
  //   cout << "Parent of node " << i << " la: " << parent[i] << " and deep of node " << i << " = " << dfs(i, parent) << " and distance -> 0: " << finddistan(i,parent,distance) << endl;
  // }




  // cout << endl;
	// int P[100][100];
	// int T[] = {0,0,0,1,1,1,2,6,6};
	// process3(9,T,P);
	// for (int i = 0; i < 9; i++) {
	// 	for (int j = 0; 1 << j < 9; j++)
	// 		cout << P[i][j] << " "; 
	// 	cout << endl;
	// }
}