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

int n, m;
void solve() {
   while(1) {
    vector<int>a(10001), b(10001);
    cin >> n;
    if(n == 0) { return; }
    for(int i = 0; i < n; i++) { cin >> a[i]; }
    cin >> m;
    for(int j = 0; j < m; j++) { cin >> b[j]; }
    vector<int>f(all(a));
    vector<int>s(all(b));
    for(int i = 1; i < n; i++) { f[i] += f[i - 1]; }
    for(int j = 1; j < m; j++) { s[j] += s[j - 1]; }
    int ans = 0, cf = 0, cs = 0;
    for(int i = 0; i < n; i++) {
        auto j = lower_bound(b.begin(), b.begin() + m, a[i]);
        if(j == b.begin() + m || *j != a[i]) continue;
        int fa = f[i] - cf;
        int fb = s[j - b.begin()] - cs;
        cf = f[i]; cs = s[j - b.begin()];
        ans = ans + max(fa, fb);
    }
    int lastA = f[n - 1] - cf;
    int lastB = s[m - 1] - cs;
    cout << ans + max(lastA, lastB) << endl;
   }
}

int main(){
    faster();
    solve();
    return 0;
}