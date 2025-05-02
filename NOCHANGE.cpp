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

int a[6], f[100001];
int k, n;

void solve() {
    cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) a[i] += a[i - 1];
    f[0] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = a[i]; j <= k; j++) {
            f[j] |= f[j - a[i]];
        }
    }
    cout << ((f[k]) ? "YES" : "NO");
}
//prefix
// 21 : 9 2 1 
//    : 9 11 12

// 12 -> : 9, 2, 1
// 11 -> : 9, 2
// 9  -> : 9
// => duyệt phần tử từ n-1 => 0, phần tử đằng trước, luôn được chọn nhiều hơn phần tử sau.
int main(){
    faster();
    solve();
    return 0;
}