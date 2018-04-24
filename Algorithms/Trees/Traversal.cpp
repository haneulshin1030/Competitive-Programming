#include<bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> adj (n);
vector<int> cnt (n); 

void dfs (int s, int e) {
    cnt[s] = 1;
    for (auto u : adj[s]) {
        if (u != e) {
            dfs (u, s);
            cnt[s] += cnt[u];
        }
    }
}

int main() {


}
