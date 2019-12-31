#include <bits/stdc++.h>
using namespace std;

// initialize so parent[i] = i, sz[i] = 1
vector<int> parent, sz;

int find(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        if(sz[pa] < sz[pb])
            swap(pa, pb);
        sz[pa] += sz[pb];
        parent[pb] = pa;
    }
}

int main() {
   
}
