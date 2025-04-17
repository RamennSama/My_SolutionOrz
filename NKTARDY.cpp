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

bool cmp(const pair<ii, int> &a, const pair<ii, int> &b) {
    if (a.fi.se != b.fi.se) return a.fi.se < b.fi.se;
    return a.fi.fi < b.fi.fi;
}
// luu ca vi tri, tranh viec bi mat vi tri quen mat:))
void solve() {
    int n, total = 0;
    cin >> n;
    vector<pair<ii, int>>a(n);
    vector<int>notLate;
    vector<int>Late;
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi.fi;
        a[i].se = i + 1;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi.se;
    }
    sort(all(a), cmp);
    priority_queue<ii>pq;
    for(int i = 0; i < n; i++) {
        total = total + a[i].fi.fi;
        pq.emplace(a[i].fi.fi, a[i].se);
        notLate.push_back(a[i].se);
        while(!pq.empty() && total > a[i].fi.se) {
            ii it = pq.top();
            pq.pop();
            total = total - it.fi;
            auto f = find(all(notLate), it.se);
            if(f != notLate.end()) {
                notLate.erase(f);
                Late.push_back(it.se);
            }
        }
    }
    cout << sz(Late) << endl;
    for(auto i : notLate) {
        cout << i << ' ';
    }
    for(auto i : Late) {
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    faster();
    solve();
    return 0;
}
