#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>> &adj, vector<int> &match, vector<int> &vis) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (match[v] == -1 || dfs(match[v], adj, match, vis)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int problemSolving(int k, vector<int> v) {
    int n = v.size();

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(v[j] - v[i]) >= k)
                adj[i].push_back(j);
        }
    }

    vector<int> match(n, -1);
    int maxMatching = 0;

    for (int i = 0; i < n; i++) {
        vector<int> vis(n, 0);
        if (dfs(i, adj, match, vis))
            maxMatching++;
    }

    return n - maxMatching;
}