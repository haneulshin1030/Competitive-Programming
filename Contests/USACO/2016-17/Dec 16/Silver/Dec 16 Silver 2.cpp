#include<bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("citystate.out");
    ifstream fin ("citystate.in");

    int n;
    fin >> n;
    string c;
    string s;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        fin >> c;
        c = c.substr (0, 2);
        fin >> s;
        string w = c + s;
        if (c != s) {
            if (m.find (w) != m.end()) {
                m[w]++;
            } else {
                m.insert (make_pair (w, 1));
            }
        }
    }
    int ans = 0;

    for (auto itr = m.begin(); itr != m.end(); itr++) {
        string s = itr -> first;
        s = (itr -> first).substr (2, 2) + (itr -> first).substr (0, 2);
        if (m.find (s) != m.end()) {
            ans += (itr-> second) * m[s];
        }
    }
    ans /= 2;
    fout << ans << endl;
}
