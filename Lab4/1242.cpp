#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

vector<int> parent[1001];
vector<int> children[1001];
vector<int> check(1001,false);
vector<int> arr;

void find_ancestors (int x) {
    arr.push_back(x);
    while (arr.size()>0) {
        int y = arr[0];
        arr.erase(arr.begin());
        for (int i=0; i < parent[y].size(); i++) {
            if (!check[parent[y][i]]) {
                check[parent[y][i]] = true;
                arr.push_back(parent[y][i]);
            }
        }
    }
}

void find_descendants (int x) {
    arr.push_back(x);
    while (arr.size()>0) {
        int y = arr[0];
        arr.erase(arr.begin());
        for (int i=0; i < children[y].size(); i++) {
            if (!check[children[y][i]]) {
                check[children[y][i]] = true;
                arr.push_back(children[y][i]);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    int u, v;
    char s[100];
    while (1){
	    scanf("%s",s);
	    if (strcmp(s,"BLOOD") == 0) {
	        break;
	    }
	    sscanf(s,"%d",&v); 
	    scanf("%d",&u);
	    parent[v].push_back(u); 
	    children[u].push_back(v);
    }

    while (scanf("%d",&u) != EOF){
        check[u] = true;
        find_ancestors(u);
        find_descendants(u);
    }
    int checkwolf = 0;
    for (int i = 1; i <= N; i++) {
        if (check[i] == false) {
            cout << i << " ";
            checkwolf = 1;
        }
    }
    if (checkwolf == 0) 
        cout << 0;
    return 0;
}