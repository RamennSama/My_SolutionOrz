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

void solve() {
    int t = 1;
    cin >> t;
    while(t--) {
        string s; cin >> s;
        int ff[2004], fs[2004], ans = 0, n = s.length();
        mem(ff, 0); mem(fs, 0);
        for(int i = 1; i < n; i++) ff[i] = ff[i - 1] + (s[i - 1] == 'K');
        for(int i = n - 2; i >= 0; i--) fs[i] = fs[i + 1] + (s[i + 1] == 'K');
        for(int i = 0; i < s.length(); i++)  {
            if(s[i] == 'E') {
                ans = ans + (ff[i] * fs[i]);
            }
        }
        cout << ans << endl;
    }
}

int main(){
    faster();
    solve();
    return 0;
}