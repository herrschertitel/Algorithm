/******************************************************************************  
- LCA of n1 and n2 using one DFS on the Tree 
- Distance between n1 and n2 = dis(n1,root)+dis(n2,root)-2dis(lca(n1,n2),root) 
- Use struct to store the adjacent vertices of v and the distance from v to the adjacent vertices
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
#define MAXN 100005
#define level 16
 
// vector <int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];
int Len[MAXN];  //disance betwee node and root

typedef struct {
    int u; //adjacent vertices of v
    int w; //distance between v and u
} edge;

vector <edge> tree1[MAXN];

/* LCA of n1 and n2 using one DFS on the Tree  */

// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(int cur, int prev, int leng) {
    Len[cur] = Len[prev] + leng;
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i=0; i<tree1[cur].size(); i++) {
        if (tree1[cur][i].u != prev)
            dfs(tree1[cur][i].u, cur, tree1[cur][i].w);
    }
}
 
// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(int n) {
    for (int i=1; i<level; i++) {
        for (int node = 1; node <= n; node++) {
            if (parent[node][i-1] != -1)
                parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
}
 
// Returning the LCA of u and v
// Time complexity : O(log n)
int lca(int u, int v) {
    if (depth[v] < depth[u])
        swap(u, v);
 
    int diff = depth[v] - depth[u];
 
    // Step 1 of the pseudocode
    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];
 
    // now depth[u] == depth[v]
    if (u == v)
        return u;
 
    // Step 2 of the pseudocode
    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
 
    return parent[u][0];
}

void addEdge(int u,int v, int w) {
    tree1[u].push_back({v,w});
    tree1[v].push_back({u,w});
}

int main() {
    memset(parent,-1,sizeof(parent));
    vector<int> result;
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      addEdge(u+1,v+1,w);
    }
    depth[0] = 0;
 
    // running dfs and precalculating depth of each node.
    dfs(1,0,0);
 
    // Precomputing the 2^i th ancestor for every node
    precomputeSparseMatrix(n);
    int m;
    cin >> m;
	  for (int i = 1; i <= m; i++) {
		  int u, v;
		  cin >> u >> v;
		  result.push_back(Len[u+1] + Len[v+1] - 2 * Len[lca(u+1, v+1)]);
	  }
	  for (int i = 0; i < m; i++)
	    cout << result[i] << endl;
    return 0;
}