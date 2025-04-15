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
vector<int>t(N * 2 * 4);
vector<int>f(N * 2);
vector<int>a(N);

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = f[tl];
    } else {
        int mid = (tl + tr) >> 1;
        build(v << 1, tl, mid);
        build(v << 1 | 1, mid + 1, tr);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return 1e9 + 5;
    if(l <= tl && tr <= r) {
        return t[v];
    }
    int mid = (tl + tr) >> 1;
    int gl = get(v << 1, tl, mid, l, r);
    int gr = get(v << 1 | 1, mid + 1, tr, l, r);
    return min(gl, gr);
}

void solve() {
    int n; cin >> n;
    int ans = n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    f[0] = a[0];
    for(int i = 1; i < n * 2; i++) {
        f[i] = f[i - 1] + a[i % n];
    }
    build(1, 0, 2 * n - 1);
    for(int i = 0; i < n; i++) {
        int pre = i == 0 ? 0 : f[i - 1];
        int seg = get(1, 0, 2 * n - 1, i, i + n - 1); // doan cong don lien tiep
        if(seg > pre) { continue; }
        ans--;
    }
    cout << ans << endl;
}

int main(){
    faster();
    solve();
    return 0;
}
