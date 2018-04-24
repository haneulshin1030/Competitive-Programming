#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<long long, int> pii;
bool vis[n];
vector <pii> adj[n];

long long prim (int x) {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    int y;
    long long minc = 0;
    pii p;
    q.push ({0, x});
    while (!q.empty()) {
        p = q.top();
        q.pop();
        x = p.second;
        if (vis[x])
            continue;
        minc += p.first;
        vis[x] = true;
        for (int i = 0; i < adj[x].size(); i++) {
            y = adj[x][i].second;
            if (!vis[y])
                q.push (adj[x][i]);
        }
    }
    return minc;
}

int main() {



}
