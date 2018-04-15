#include<bits/stdc++.h>

using namespace std;

#define INF 1<<30
int n;

int bfs (int x, int y, vector<vector<int>> &adj) {
    queue<int> q;
    vector<bool> vis (1000);
    vector<int> dist (1000, INF);
    int d = 0;
    dist[x] = 0;
    q.push (x);
    while (!q.empty()) {
        d++;
        int a = q.front();
        q.pop();

        for (auto u : adj[a]) {
            if (dist[u] == INF) {
                dist[u] = d;
                q.push ({u});
            }
        }
    }
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": " << dist[i] << endl;
    }
    return dist[y];
}


int main() {


}
