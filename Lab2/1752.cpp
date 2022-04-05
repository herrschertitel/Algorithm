#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
 
const int maxn = 20202;
const int maxq = 50101;
struct listquery {
    int d, id;  // the Queries are grouped by v, see the array qr
};
 
vector<int> gr[maxn];

vector<listquery> qr[maxn];
int result[maxq];
 
vector<int> fathers;

void dfs(int u, int p) {
    fathers.push_back(u);
    for (auto i: qr[u]) {
        if (fathers.size() <= i.d) continue;
        result[i.id] = fathers.rbegin()[i.d];
    }
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    fathers.pop_back();
}
 
int furthest(int u, int n) {
    queue<int> qu;
    vector<bool> vis(n + 1);
    qu.push(u);
    vis[u] = true;
    while (qu.size()) {
        u = qu.front();
        qu.pop();
        for (auto v: gr[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            qu.push(v);
        }
    }
    return u;
}
 
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    for (int i = 0; i < q; ++i) {
        int u, d;
        cin >> u >> d;
        qr[u].push_back({d, i});
        
    }
    
    int x = furthest(1, n);
    // cout << x << endl;
    dfs(x, x);
    // for (int i = 0; i < fathers.size(); i++) {
    //     cout << fathers[i] << " ";
    // }
    // cout << endl;
    x = furthest(x, n);
    dfs(x, x);
    // for (int i = 0; i < fathers.size(); i++) {
    //     cout << fathers[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < q; ++i) cout << result[i] << '\n';
    
    return 0;
}