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


string a, b, sub = "";
int n, m;
int f[2000 + 1][2000 + 1];

void solve() {
    cin >> a;
    b = a;
    n = a.length();
    m = b.length();
    reverse(b.begin(), b.end());
    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    while(f[n][m] > 0) {
        if(a[n] == b[m]) {
            sub = sub + a[n]; m--, n--;
        } else if(f[n][m] == f[n - 1][m]) {
            n--;
        } else {
            m--;
        }
    }
    cout << sub << endl;
}

int main(){
    faster();
    solve();
    return 0;
}