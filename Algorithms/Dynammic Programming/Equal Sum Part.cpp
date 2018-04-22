#include<bits/stdc++.h>

using namespace std;

int n;
bool part (int a[], int n) {
    int sum = 0;
    bool p[sum / 2 + 1][n + 1];
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    for (int j = 0; j <= n; j++) {
        p[0][j] = true;
    }
    for (int i = 1; i <= sum / 2; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[i][j - 1] || (i >= a[j - 1] && p[i - a[j - 1]][j - 1])) {
                p[i][j] = true;
            }
        }
    }
    return p[sum / 2][n];
}

int main() {

    cin >> n;
    int a[n];
    FOR (i, n) {
        cin >> a[i];
    }
    cout << part (a, n) << endl;
}
