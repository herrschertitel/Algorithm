/******************************************************************************
Take advantage of the tree's diameter. The furthest vertex possible from any vertex in the tree is a 
diameter endpoint of the tree. So it is clear that if the d-value of the query is farther than the distance from the vertex v to the (further) end of the diameter, 
the answer is that there is no vertex to be found. conversely, a satisfying vertex is a vertex lying on the path from v to that (further) endpoint. 
To find this vertex quickly we can do dfs twice from the two ends of the diameter, and in the dfs process we save the entire ancestor list. 
To a certain vertex u, we will process (offline) the entire query of this vertex. 
*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
 
const int MAXN = 20005;
const int MAXQ = 50005;
struct listquery {
    int d, id;  // the Queries are listadj_verouped by v, see the array lisque_ver
};
 
vector<int> listadj_ver[MAXN]; // list of adjacent vertices

vector<listquery> lisque_ver[MAXN]; // list of queries for each vertex
int result[MAXQ];   
 
vector<int> fathers; //list of vertices passed


/* use DFS to traverse all vertices, 
at each vertex will traverse all queries related to that vertex */
void DFS(int u, int p) {
    fathers.push_back(u);
    for (int i = 0; i < lisque_ver[u].size(); i++) {
        if (fathers.size() <= lisque_ver[u][i].d) continue;
        result[lisque_ver[u][i].id] = fathers[fathers.size()-lisque_ver[u][i].d-1];
    }
    for (int i = 0; i < listadj_ver[u].size(); i++) {
        if (listadj_ver[u][i] == p) continue;
        DFS(listadj_ver[u][i],u);
    }
    fathers.pop_back();
}

/* find the vertex furthest from u */

int furthest(int u, int n) {
    queue<int> qu;
    vector<bool> check(MAXN);
    qu.push(u);
    check[u] = true;
    while (qu.size()) {
        u = qu.front();
        qu.pop();
        for (int i = 0; i < listadj_ver[u].size(); i++) {
            if (check[listadj_ver[u][i]]) continue;
            check[listadj_ver[u][i]]= true;
            qu.push(listadj_ver[u][i]);
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
        listadj_ver[u].push_back(v);
        listadj_ver[v].push_back(u);
    }
    for (int i = 0; i < q; ++i) {
        int u, d;
        cin >> u >> d;
        lisque_ver[u].push_back({d, i});
    }
    int x = furthest(1, n);
    DFS(x, x);
    x = furthest(x, n);
    DFS(x, x);
    for (int i = 0; i < q; ++i) cout << result[i] << endl;
    return 0;
}
