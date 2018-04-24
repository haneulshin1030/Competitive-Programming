#include <bits/stdc++.h>
using namespace std;

#define INF (LLONG_MAX/2)

typedef long long ll;

int main() {
    ofstream fout ("cowroute.out");
    ifstream fin ("cowroute.in");
    int n, a, b;
    fin >> a >> b >> n;
    a--;
    b--;

    vector<vector<ll>> adj (1000, vector<ll> (1000, INF));
    vector<vector<int>> steps (1000, vector<int> (1000));

    for (int i = 0; i < n; i++) {
        int c, m;
        fin >> c >> m;

        vector<int> f (m);
        for (int j = 0; j < m; j++) {
            fin >> f[j];
            f[j]--;

            for (int k = 0; k < j; k++) {
                if (c < adj[f[k]][f[j]]) {
                    adj[f[k]][f[j]] = c;
                    steps[f[k]][f[j]] = j - k;

                } else if (c == adj[f[k]][f[j]])
                    steps[f[k]][f[j]] = min (steps[f[k]][f[j]], j - k);
            }
        }
    }

    vector<bool> vis (1000);
    vector<ll> a_dist (1000, INF);
    vector<int> a_steps (1000);

    a_dist[a] = a_steps[a] = 0;

    for (int i = 0; i < 1000; i++) {
        int u = -1;
        for (int j = 0; j < 1000; j++)
            if (!vis[j])
                if (u == -1 || a_dist[j] < a_dist[u])
                    u = j;

        vis[u] = true;
        for (int j = 0; j < 1000; j++) {
            if (a_dist[j] > a_dist[u] + adj[u][j]) {
                a_dist[j] = a_dist[u] + adj[u][j];
                a_steps[j] = a_steps[u] + steps[u][j];
            } else if (a_dist[j] == a_dist[u] + adj[u][j]) {
                a_steps[j] = min (a_steps[j], a_steps[u] + steps[u][j]);
            }

        }
    }


    if (a_dist[b] == INF)
        fout << "-1 -1\n";
    else
        fout << a_dist[b] << " " << a_steps[b] << "\n";

    return 0;
}
