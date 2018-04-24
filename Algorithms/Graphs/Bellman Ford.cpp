#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30
#define FOR(i,a) for(int i=0;i<a;i++)
int n;

int bf (int x, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist (n, INF);
    dist[x] = 0;
    bool nc = false; //negative cycle
    FOR (j, n) {
        nc = false;
        FOR (i, n) {
            for (auto e : adj[i]) {
                int a = i;
                int b, w;
                tie (b, w) = e; //copying edge values

                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    nc = true;
                }
                if (!nc) {
                    break;
                }
            }
        }
    }
    if (nc) {
        return -1;
    } else {
        int ans = INF;
        FOR (i, n) {
            ans = min (ans, dist[i]);
        }
        return ans;
    }

}
int main() {


}
