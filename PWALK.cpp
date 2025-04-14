#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> ii;
typedef pair<ll, int> lli;
typedef unsigned long long ull;
#define fi first
#define se second
#define pb push_back
#define ed cout << "\n"
#define no cout << "NO\n"
#define ye cout << "YES\n"
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define mem(a,b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define sz(A) (int) A.size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 1e5 + 15;
const int inf = 1e9;
//const int oo = inf;

unordered_map<int, vector<int>>adj;
int f[1001][1001];
int d[1001][1001];
int n, q, cur;

void dfs(int u, int par, int r, int sum) {
    f[r][u] = sum;
    for(auto v : adj[u]) {
        if(v == par) continue;
        dfs(v, u, r, sum + d[u][v]);
    }
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        d[x][y] = d[y][x] = z;
    }
    for(int i = 1; i <= n; i++) {
        dfs(i, -1, i, 0);
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << f[x][y] << endl;
    }
}

int main(){
    faster();
    solve();
    return 0;
}