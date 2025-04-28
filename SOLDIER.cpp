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
const int oo = 1e9;

// tag : DP
int n, m, ans = 0;
vector<ii>a[106];
vector<vector<int>>f(7, vector<int>(1006, -1));

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(ii(y, z));
    }
    for(int i = 0; i < a[1].size(); i++) {
        f[1][a[1][i].fi] = max(f[1][a[1][i].fi], a[1][i].se);
    }
    for(int i = 2; i <= 6; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            for(int t = a[i][j].fi; t <= m; t++) {
                if(f[i - 1][t - a[i][j].fi] != -1) {
                    f[i][t] = max(f[i][t], min(f[i - 1][t - a[i][j].fi], a[i][j].se));
                }
            }
        }
    }
    for(int t = 0; t <= m; t++) {
        if(f[6][t] != -1) {
            ans = max(ans, f[6][t]);
        }
    }
    cout << ans << endl;
}
// f[6][t] != -1 : la chat luong nho nhat cua ptu ben trong cac mon do tu 1 -> 6 voi tong la t

// tag : greedy
void solve() {
    int n, m, res = 0, total = 0, v;
    cin >> n >> m;
    int f[7], u[7];
    mem(f, -1);
    mem(u, -1);
    while(n--) {
        int t, p, d;
        cin >> t >> p >> d;
        if(f[t] == -1) {
            total = total + p;
            u[t] = p; 
            f[t] = d;
        } else if(d > f[t] && total - u[t] + p <= m) {
            total = total - u[t] + p;
            u[t] = p; 
            f[t] = d;
        }
        int ok = 1;
        if(f[1] == -1 || total > m) continue;
        v = f[1];
        for(int i = 2; i <= 6; i++) {
            v = min(v, f[i]);
            if(f[i] == -1) { 
                ok = 0; break;
            }
        }
        if(ok) res = max(res, v);
    }
    cout << res << endl;
}
//
int main(){
    faster();
    solve();
    return 0;
}
