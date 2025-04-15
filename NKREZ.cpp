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
//const int N = 1e5 + 15;
const int inf = 1e9;
//const int oo = inf;

bool cmp(ii a, ii b) {
    return a.se < b.se;
}
int ans = -1;
void solve() {
    int n; cin >> n;
    vector<ii>a(n);
    vector<int>f(10001, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin(), a.end(), cmp);
    f[0] = a[0].se - a[0].fi;
    for(int i = 1; i < n; i++) {
        f[i] = a[i].se - a[i].fi;
        int q = -1;
        for(int j = 0; j < i; j++) {
            if(a[j].se > a[i].fi) { continue; }
            else {
                q = max(q, f[j]);
            }
        }
        f[i] = q == -1 ? f[i] : f[i] + q;
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
}

int main(){
    faster();
    solve();
    return 0;
}