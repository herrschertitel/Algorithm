#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 20202;
const int maxq = 50101;
struct Query {
    int d, id;  // the Queries are grouped by v, see the array qr
};
 
int n, q;
vector<int> gr[maxn];
vector<Query> qr[maxn];
int ans[maxq];
 
vector<int> ancestors;
void dfs(int u, int p) {
    ancestors.push_back(u);
    for (auto it: qr[u]) {
        if ((int)ancestors.size() <= it.d) continue;
        ans[it.id] = ancestors.rbegin()[it.d];
    }
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    ancestors.pop_back();
}
 
int furthest(int u) {
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
    cin.tie(0)->sync_with_stdio(0);
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
    
    int x = furthest(1);
    dfs(x, x);
    x = furthest(x);
    dfs(x, x);
    
    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
    
    return 0;
}