#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector < vector <int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;

#define FOR(i,a) for(int i = 0; i < a; i++)

#define mp make_pair
#define pb push_back


int main() {
    freopen ("A-large-practice.in", "r", stdin);
    freopen ("A-large-practice.out", "w", stdout);
    int T;
    cin >> T;
    FOR (t, T) {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> v (r, vector<char> (c));
        FOR (i, r) {
            bool first = true;
            char fir;
            int ind = -1;
            char cur = '!';
            FOR (j, c) {
                cin >> v[i][j];
                if (v[i][j] != '?') {
                    cur = v[i][j];
                    if (first) {
                        fir = cur;
                        first = false;
                        ind = j;
                    }
                } else if (cur != '!') {
                    v[i][j] = cur; //fill in horizontally
                }
            }
            if (ind != -1) {
                FOR (k, ind) {
                    v[i][k] = fir;
                }
            }
        }
        int ind;
        FOR (i, r) {
            if (v[i][0] != '?') {
                ind = i;
                break;
            }
        }
        int prev = ind;

        for (int i = ind + 1; i < r; i++) {
            if (v[i][0] == '?') {
                FOR (j, c) {
                    v[i][j] = v[prev][j];
                }
            } else {
                prev = i;
            }
        }
        prev = ind;
        for (int i = ind - 1; i >= 0; i--) {
            if (v[i][0] == '?') {
                FOR (j, c) {
                    v[i][j] = v[prev][j];
                }
            } else {
                prev = i;
            }
        }
        cout << "Case #" << t + 1 << ":" << endl;

        FOR (i, r) {
            FOR (j, c) {
                cout << v[i][j];
            }
            cout << endl;
        }
    }
}
