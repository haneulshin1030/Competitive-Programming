#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30
#define FOR(i,a) for(int i=0;i<a;i++)
int n;
vector<tuple<int, int, int>> edges; //from node, to node, weight

int bf (int x) {
    vector<int> dist (n, INF);
    dist[x] = 0;
    FOR (i, n) {
        for (auto e : edges) {
            int a, b, w;
            tie (a, b, w) = e; //copying edge values
            dist[b] = min (dist[b], dist[a] + w);
        }
    }

}
int main() {


}
