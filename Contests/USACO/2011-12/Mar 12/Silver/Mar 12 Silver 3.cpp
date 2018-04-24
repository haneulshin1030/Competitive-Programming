#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a) for(int i = 0; i < a; i++)
typedef vector<int> vi;
#define pb push_back

int n, x, y, z;

vi a;
vi b;
int ed (vi a, vi b, int m, int n) {
    int dp[m + 1][n + 1];
    FOR (i, m + 1) {
        FOR (j, n + 1) {
            if (i == 0) {
                dp[i][j] = j * x;
            } else if (j == 0) {
                dp[i][j] = i * y;
            } else {
                dp[i][j] = min (min (x + dp[i][j - 1], y + dp[i - 1][j]), dp[i - 1][j - 1] + z * abs (a[i - 1] - b[j - 1]));
            }
        }
    }
    return dp[m][n];
}
int main() {
    //freopen ("landscape.in", "r", stdin);
    //freopen ("landscape.out", "w", stdout);
    int c, d;
    cin >> n >> x >> y >> z;
    FOR (i, n) {
        cin >> c >> d;
        FOR (j, c) {
            a.pb (i);
        }
        FOR (j, d) {
            b.pb (i);
        }
    }
    cout << ed (a, b, a.size(), b.size()) << endl;
}
