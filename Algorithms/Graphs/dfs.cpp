#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

// recursive
void dfs (int s) {
    if (vis[s]) return;
    vis[s] = true;
    // process node s
    for (auto u : adj[s]) {
        dfs (u);
    }
}

// stack
void dfs_s (int x) {
    stack<int> s;
    vector<bool> v;
    
    v[x] = true;
    s.push(x);
    
    while(!s.empty()){
        int a = s.top();
        s.pop();
        
        for(auto u: adj[a]){
            if(!v[u]){
                v[u] = true;
                s.push(u);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vis.resize (n);
    adj.resize (n);
    //fill adj list
    dfs (0);
}
