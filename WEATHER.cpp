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
const int N = 105;
const int inf = 1e9;
const int oo = inf;
 
unordered_map<int, vector<int>>g;
vector<int>disc, low, f, par, joints;
vector<vector<int>>bridges;
int n, m, x, y, timer = 0, ans = 0, cur = 0;
 
int nxt() {
    int c; cin >> c;
    return c;
}
 
void __init__ () {
    disc.assign(N, -1);
    low.assign(N, 0);
    f.assign(N, 1);
    par.assign(N, -1);
    joints.assign(N, 0);
}
 
void dfs(int u) {
    int chil = 0;
    disc[u] = low[u] = ++timer;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == par[u]) {
            continue;
        }
        if(disc[v] == -1) {
            chil++;
            par[v] = u;
            dfs(v);
            f[u] = f[u] + f[v];
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) {
                bridges.push_back({v, u});
            }
            if(chil > 1 && par[u] == -1) {
                joints[u] = 1;
            }
            if(par[u] != -1 && low[v] >= disc[u]) {
                joints[u] = 1;
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}
 
 
void solve() {
    __init__();
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        x = nxt();
        y = nxt();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        if(disc[i] == -1) 
            dfs(i);
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << f[i] << ' ';
    // }
    // ed;
    for(auto e : bridges) {
        int v = e[0], u = e[1];
        int _v = f[e[0]];
        int _u = n -_v;
        ans = ans + (_v * _u);
    }
    cout << ans << endl;
}
 
int main(){
    faster();
    solve();
    return 0;
} 