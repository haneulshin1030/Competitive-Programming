#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
int n;
vector<vector<int>> adj;

// dist
int bfs (int s, int t) {
    queue<int> q;
    vector<int> dist (n, INF);
    
    dist[s] = 0;
    q.push (s);
    
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        
        for (auto u : adj[a]) {
            if (dist[u] == INF) {
                dist[u] = dist[a] + 1;
                q.push (u);
            }
        }
    }
    return dist[t];
}

/*
 for (int i = 0; i < adj.size(); i++) {
 cout << i << ": " << dist[i] << endl;
 }
 */

// vis
void bfs (int s) {
    queue<int> q;
    vector<bool> vis (n);
    
    vis[s] = true;
    q.push (s);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        
        for (auto u : adj[a]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push (u);
            }
        }
    }
}

int main() {
    cin >> n;
    adj.resize (n);
    //fill adj list
    bfs (0, n-1);
}
