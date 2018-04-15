#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a) for(int i = 0; i < a; i++)
#define pb push_back
#define x first
#define y second

int main() {
    //srand (time (0));
    int T;
    cin >> T;
    FOR (t, T) {
        int a;
        cin >> a;
        int w = sqrt (a);
        if (w * w < a) {
            w++;
        }
        a = w * w;
        vector<vector<int>> v (w, vector<int> (w));
        vector<vector<int>> u (w - 2, vector<int> (w - 2));
        vector<vector<bool>> vis (w, vector<bool> (w));

        int b = -2;
        int c = -2;
        int x = 101;
        int y = 101;
        // int sum = 0;

        while (b != 0 || c != 0) {
            if (b == -1 && c == -1) {
                break;
            }
            // sum++;
            cout << x << " " << y << endl;
            cin >> b >> c;

            if (b == 0 && c == 0) break;

            if (vis[b - 100][c - 100]) {
                continue;
            }
            vis[b - 100][c - 100] = true;
            FOR (i, 3) {
                FOR (j, 3) {
                    if (b + i - 102 >= 0 && b + i - 102 < w - 2 && c + j - 102 >= 0 && c + j - 102 < w - 2) {
                        u[b + i - 102][c + j - 102]++;
                    }
                }
            }

            int min_a = INT_MAX;
            FOR (i, w - 2) {
                FOR (j, w - 2) {
                    if (min_a > u[i][j]) {
                        min_a = u[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
            x += 101;
            y += 101;
        }
    }
}
