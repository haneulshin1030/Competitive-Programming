//for adj list
#include<bits/stdc++.h>

using namespace std;
#define INF 1<<30

int n;

int dijkstra (int x, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>> q;
    vector<bool> vis (n);
    vector<int> dist (n, INF);

    dist[x] = 0;
    q.push ({0, x});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push ({ -dist[b], b});
            }
        }
    }
    // find shortest path
    int best = 0;
    for (int i = 0; i < n * n; i++) {
        best = max (best, dist[i]);
    }
    return best;
}



int main() {


}
