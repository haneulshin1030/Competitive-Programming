#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(i,a) for(int i = 0; i < a; i++)

int main() {
    int T;
    cin >> T;
    int d;
    string p;
    FOR (t, T) {
        cin >> d >> p;
        //ignore trailing C's
        bool trail_c = true;
        int c = 0;
        int s = 0;
        int sz = p.size();

        vector<int> v (sz);
        for (int i = p.size() - 1; i >= 0; i--) {
            if (trail_c && p[i] == 'C') {
                sz--;
                continue;
            } else if (p[i] == 'C') {
                c++;
            } else {
                s++;
                trail_c = false;
            }
        }

        if (s > d) {
            cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
            continue;
        }

        int cur = 1; // remember to halve the change
        int sum = 0;
        FOR (i, sz) {
            if (p[i] == 'C') {
                cur *= 2;
                v[i] = cur;

            } else {
                v[i] = -1;
                sum += cur;
            }
        }
        if (d >= sum) {
            cout << "Case #" << t + 1 << ": " << 0 << endl;
            continue;
        }
        int ans = 0;

        for (int i = sz - 1; i >= 0; i--) {
            if (v[i] == -1) {
                continue;
            }
            if (sum - ( (sz - i - 1) * v[i] / 2) > d) {
                sum -= ( (sz - i - 1) * v[i] / 2);
                ans += (sz - i - 1);

            } else {
                int x = (sum - d) / (v[i] / 2);

                if (sum - x * (v[i] / 2) <= d) {
                    ans += x;
                    break;
                } else {
                    ans += (x + 1);
                    break;
                }
            }
            sz--;
        }

        cout << "Case #" << t + 1 << ": " << ans << endl;
    }

}
