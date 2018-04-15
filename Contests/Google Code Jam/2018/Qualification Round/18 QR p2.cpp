#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define FOR(i,a) for(int i = 0; i < a; i++)
#define pb push_back

int main() {
    int T;
    int a;
    cin >> T;
    FOR (t, T) {
        int n;
        cin >> n;
        vector<int> v;
        vector<int> v1; //even
        vector<int> v2; //odd

        FOR (i, n) {
            cin >> a;
            v.pb (a);
            if (i % 2 == 0) {
                v1.pb (a);
            } else {
                v2.pb (a);
            }
        }
        sort (v.begin(), v.end());
        sort (v1.begin(), v1.end());
        sort (v2.begin(), v2.end());

        int ind;
        int ans;
        bool ok = true;
        FOR (i, n) {
            if (i % 2 == 0) {
                ind = i / 2;
                if (v[i] != v1[ind]) {
                    ans = i;
                    ok = false;
                    break;
                }
            } else {
                ind = (i - 1) / 2;
                if (v[i] != v2[ind]) {
                    ans = i;
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << "Case #" << t + 1 << ": OK" << endl;
        } else {
            cout << "Case #" << t + 1 << ": " << ans << endl;

        }
    }

}
