#include<bits/stdc++.h>

using namespace std;

#define INF 1<<30
int n;

int dijkstra (int x, vector<vector<pair<int, int>>> &adj, vector<int> &parent) {
    priority_queue<pair<int, int>> q;
    vector<bool> vis (n);
    vector<int> dist (n);

    for (int i = 0; i < n; i++) dist[i] = INF;
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
                parent[b] = a;
                q.push ({ -dist[b], b});
            }
        }

    }
    return dist[n - 1];
}

int main() {
    //  ofstream fout ("rblock.out");
    // ifstream fin ("rblock.in");
    int m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj (n);
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a - 1].push_back ({b - 1, w});
        adj[b - 1].push_back ({a - 1, w});
    }

    vector<int> parent (n);
    vector<int> parent1 (n);
    int sp = dijkstra (0, adj, parent); //shortest path

    int ans = 0;
    int i = n - 1;

    while (i != 0) {

        int i1, j1;
        int j = parent[i];
        int t, t1;
        int c = 0;
        for (int v = 0; v < adj[i].size(); v++) {
            if (adj[i][v].first == j) {
                c++;
                i1 = v;
                t = adj[i][v].second;
                adj[i][v].second *= 2;
            }
        }
        for (int v = 0; v < adj[j].size(); v++) {
            if (adj[j][v].first == i) {
                j1 = v;
                t1 = adj[j][v].second;
                adj[j][v].second *= 2;
            }
        }
        ans = max (ans, dijkstra (0, adj, parent1));
        adj[i][i1].second /= 2;
        adj[j][j1].second /= 2;

        i = parent[i];
    }
    cout << ans - sp << endl;

}
