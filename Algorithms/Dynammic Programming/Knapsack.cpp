#include<bits/stdc++.h>

using namespace std;


#define FOR(i,a) for(int i = 0; i < a; i++)
int W, n;

vector<vector<int>> m (n + 1, vector<int> (W + 1));
vector<int> v;
vector<int> w;

int knap () {
    for (int j = 0; j <= W; j++) {
        m[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (w[i] > j) {
                m[i][j] = m[i - 1][j];
            } else {
                m[i][j] = max (m[i - 1][j], m[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    return m[n][W];
}

int main() {



}
