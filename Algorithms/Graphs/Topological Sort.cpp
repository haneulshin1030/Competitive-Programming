#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a) for(int i = 0; i < a; i++)
#define pb push_back

int n, m;
vector<int> in; //in degrees
vector<int> res; 
vector<vector<int>> adj;

void topo() {
    queue<int> q;
    FOR (i, n) {
        if (in[i] == 0) {
            q.push (i);
        }
    }
    while (q.size() != 0) {
        int x = q.front();
        q.pop();
        res.pb (x);
        for (int i : adj[x]) {
            in[i]--;
            if (in[i] == 0) {
                q.push (i);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    in.resize (n);
    adj.resize (n);
    FOR (i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb (y);
        in[y]++;
    }
    topo();
    for (int i = n - 1; i >= 0; i--) {
        cout << res[i] + 1 << " ";
    }
}
