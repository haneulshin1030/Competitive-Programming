//feast
#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a) for(int i = 0; i < a; i++)

int main() {
    freopen ("feast.in", "r", stdin);
    freopen ("feast.out", "w", stdout);

    int t, a, b;
    cin >> t >> a >> b;
    vector<vector<bool>> pos (2, vector<bool> (t + 1));
    pos[0][0] = true;

    FOR (i, t + 1) {
        if (i - a >= 0) {
            if (pos[0][i - a]) {
                pos[0][i] = true;
            }
        }
        if (i - b >= 0) {
            if (pos[0][i - b]) {
                pos[0][i] = true;
            }
        }
    }
    FOR (i, t + 1) {
        if (2 * i <= t) {
            if (pos[0][2 * i]) {
                pos[1][i] = true;
            }
        }
        if (2 * i + 1 <= t) {
            if (pos[0][2 * i + 1]) {
                pos[1][i] = true;
            }
        }
        if (i - a >= 0) {
            if (pos[1][i - a]) {
                pos[1][i] = true;
            }
        }
        if (i - b >= 0) {
            if (pos[1][i - b]) {
                pos[1][i] = true;
            }
        }
    }

    int i = t;
    while (!pos[1][i]) {
        i--;
    }
    cout << i << endl;
}
