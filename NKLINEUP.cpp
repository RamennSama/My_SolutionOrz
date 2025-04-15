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

struct f {
    int mi;
    int mx;
    int val;
    f() {}
    
    f(int _mi, int _mx, int _val) : mi(_mi), mx(_mx), val(_val) {}

};
vector<f>t(N * 4);
int a[N];
int n, q;

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].mi = a[tl];
        t[v].mx = a[tl];
    } else {
        int mid = (tl + tr) >> 1;
        build(v << 1, tl, mid);
        build(v << 1 | 1, mid + 1, tr);
        t[v].mi = min(t[v << 1].mi, t[v << 1 | 1].mi);
        t[v].mx = max(t[v << 1].mx, t[v << 1 | 1].mx);
    }
}

int get(int v, int tl, int tr, int l, int r, char c) {
    if(tl > r || l > tr) {
        return c == 'u' ? -1 : 1e9;
    }
    if(l <= tl && tr <= r) {
        return c == 'u' ? t[v].mx : t[v].mi; 
    }
    int mid = (tl + tr) >> 1;
    int gl = get(v << 1, tl, mid, l, r, c);
    int gr = get(v << 1 | 1, mid + 1, tr, l, r, c);
    return c == 'u' ? max(gl, gr) : min(gl, gr);
}

void solve() {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while(q--) {
        int l, r;
        cin >> l >> r; 
        l--, r--;
        cout << get(1, 0, n - 1, l, r, 'u') - get(1, 0, n - 1, l, r, 'd') << endl;
    }
}

int main(){
    faster();
    solve();
    return 0;
}
