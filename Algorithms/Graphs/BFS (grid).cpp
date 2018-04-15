#include<bits/stdc++.h>
using namespace std;

int m, n;
void bfs (vector<vector<bool>> &vis, int x, int y) {
    queue<pair<int, int> >q;
    q.push ({x, y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (vis[x][y]) continue;
        vis[x][y] = true;
        //  cout << "(" << x << ", " << y << ")" << endl;

        if (x > 0) {
            q.push ({x - 1, y});
        }
        if (x < m - 1) {
            q.push ({x + 1, y});
        }
        if (y > 0) {
            q.push ({x, y - 1});
        }
        if (y < n - 1) {
            q.push ({x, y + 1});
        }
    }
}
int main() {


}
