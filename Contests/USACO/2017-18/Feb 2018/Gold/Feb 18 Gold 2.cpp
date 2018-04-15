#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector < vector <int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;

#define FOR(i,a) for(int i = 0; i < a; i++)

#define pb push_back
#define x first
#define y second
#define INF 1>>30

vector<int> cnt;
vector<int> v;
vector <vector<pii>> adj;
vector<bool> vis;
vector<ll> sum;
vector<int> depth;
vector<string> name;
int d;
int prevx = 0;

//going down
void dfs_u (int s);
void dfs_d (int s) {
    vis[s] = true;
    if (s != 0) {
        sum[s] = sum[prevx] + cnt[prevx] * 3 - cnt[s] * (name[s].size() + 1);
    }
    FOR (i, adj[s].size())   {
        if (!vis[adj[s][i].x]) {
            prevx = s;
            if (adj[s][i].y == 0) {
                //up
                dfs_u (adj[s][i].x);
            } else {
                dfs_d (adj[s][i].x);
            }
        }
    }
}

//going up
void dfs_u (int s) {
    vis[s] = true;
    if (s != 0) {
        sum[s] = sum[prevx] - cnt[s] * 3 + cnt[prevx] * (name[prevx].size() + 1);
    }
    FOR (i, adj[s].size())   {
        if (!vis[adj[s][i].x]) {
            prevx = s;
            if (adj[s][i].y == 0) {
                //up
                dfs_u (adj[s][i].x);
            } else {
                dfs_d (adj[s][i].x);
            }
        }
    }
}


void dfs1 (int s) {
    depth[s] = d;
    //get subtree sizes
    vis[s] = true;
    if (v[s] == 0) {
        cnt[s] = 1;
        return;
    }
    FOR (i, adj[s].size())   {
        d++;
        if (!vis[adj[s][i].x]) {
            dfs1 (adj[s][i].x);
            cnt[s] += cnt[adj[s][i].x];
        }
        d--;
    }
}

int main() {
    int n, a, m, d = 0;
    cin >> n;
    cnt.resize (n);
    vis.resize (n);
    adj.resize (n);
    sum.resize (n);
    depth.resize (n);
    string s1;

    FOR (i, n) {
        cin >> s1 >> m;
        name.pb (s1);
        if (m == 0) {
            v.pb (0); //file
        } else {
            v.pb (1); //folder
            FOR (j, m) {
                cin >> a;
                a--;
                adj[i].pb ({a, 1}); 
                adj[a].pb ({i, 0}); 
            }
        }
    }
    dfs1 (0);

    sum[0] = 0;
    FOR (i, n) {
        if (v[i] == 0) {
            sum[0] += depth[i];
        }
        sum[0] += cnt[i] * name[i].size();

    }

    fill (vis.begin(), vis.end(), 0);
    dfs_d (0);
    ll mins = LONG_MAX;

    FOR (i, n) {
        cout << sum[i] << endl;
        cout << mins << endl;
        if (v[i] == 0 && sum[i] < mins) {
            mins = sum[i];
        }
    }
    cout << mins << endl;
}

