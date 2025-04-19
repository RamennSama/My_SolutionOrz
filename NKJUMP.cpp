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
const int oo = inf;

unordered_map<int ,vector<int>>g;
unordered_map<int ,vector<int>>e;
vector<int>f(1001, -1);
int ans = 0;

int dfs(int u) {
    if(f[u] != -1) return f[u];
    f[u] = 1;
    for(auto v : g[u]) {
        f[u] = max(f[u], dfs(v) + 1);
    }
    return f[u];
}

void solve() {
    int n; cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        e[a[i]].push_back(i + 1);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = a[i] + a[j];
            if(i == j || sum > inf) {
                continue;
            }
            if(e.find(sum) != e.end()) {
                g[i + 1].push_back(e[sum][0]);
                g[j + 1].push_back(e[sum][0]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}

int main(){
    faster();
    solve();
    return 0;
}
