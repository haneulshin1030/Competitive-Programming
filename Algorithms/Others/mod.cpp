#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return a * 1ll * b % MOD;
}

// to compute a^{-1} (mod p) let b = p-2
int mod_pow(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

// to compute a^{-1} (mod m), let b = m; answer is x
int gcd_extended(int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd_extended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// returns a^{-1} (mod m)
int mod_inv(int a, int m) {
    int x = 0, y = 0;
    gcd_extended(a, m, x, y);
    return (x % m + m) % m;
}

int main() {

}
