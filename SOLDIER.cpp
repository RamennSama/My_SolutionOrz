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

int main(){
    faster();
    solve();
    return 0;
}
