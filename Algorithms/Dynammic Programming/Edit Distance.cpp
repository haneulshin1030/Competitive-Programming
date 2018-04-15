#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a) for(int i = 0; i < a; i++)

int edit (string s1, string s2, int m, int n) {
    int dp[m + 1][n + 1];
    FOR (i, m + 1) {
        FOR (j, n + 1) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min (dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main() {


}
