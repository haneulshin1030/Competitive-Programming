#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs (int s) {
    if (vis[s]) return;
    vis[s] = true;
    // process node s
    for (auto u : adj[s]) {
        dfs (u);
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize (n);
    //fill adj list
    vis.resize (n);
    dfs (0);
}
