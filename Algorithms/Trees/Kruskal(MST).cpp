#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;
set<pair<int, pii>> s;

int n, ans = 0;

vector<int> parent;
vector<int> sz;

int find (int v) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void unite (int a, int b, int w) {
    int pa = find (a);
    int pb = find (b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) {
            swap (pa, pb);
        }
        sz[pa] += sz[pb];
        parent[pb] = pa;
        ans += w;
    }
}

int main() {
    int e;
    cin >> n >> e;

    sz.resize (n);
    fill (sz.begin(), sz.end(), 1);
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        s.insert ({w, {a, b}});
    }

    parent.resize (n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    //Graph adj (v);
    for (auto it = s.begin(); it != s.end(); it++) {
        int w = it->first, a = it->second.first, b = it->second.second;
        unite (a, b, w);
    }

    return 0;
}
