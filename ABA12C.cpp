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

int n, k;
int p[101];
vector<vector<int>>f;

// dp[t][kg]: Chi phí nhỏ nhất để đạt được kg kilogam táo bằng cách dùng đúng t gói táo.
void solve() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) { cin >> p[i]; }
    f.assign(101, vector<int>(101, oo));

    // if (n == 0 && k > 0) { cout << -1 << endl; return; }
    // if (k == 0) { cout << 0 << endl; return; }
    
    f[0][0] = 0;
    for(int t = 0; t < n; t++) { // so goi tao
        for(int kg = 0; kg <= k; kg++) { // so kg
            if(f[t][kg] == inf) continue;
            for(int i = 0; i < k; i++) {
                if(p[i] == -1) continue;
                int j = i + 1;
                if(kg + j <= k) f[t + 1][kg + j] = min(f[t + 1][kg + j], f[t][kg] + p[i]);
            }
        }
    }
    // chi phí nhỏ nhất để đạt đúng k kg
    int ans = inf;
    for(int t = 0; t <= n; t++) {
        ans = min(ans, f[t][k]);
    }
    ans = (ans == inf) ? -1 : ans;
    cout << ans << endl;
}

int main(){
    faster();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}