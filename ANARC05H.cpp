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
const int N = 105;
const int inf = 1e9;
const int oo = inf;

//back track
// int f(int pos, int prev) {
//     if(pos == s.length()) { return 1; }
//     int res = 0, cur = 0;
//     for(int i = pos; i < s.length(); i++) {
//         cur = cur + (s[i] - '0');
//         if(cur >= prev) {
//             res = res + f(i + 1, cur);
//         }
//     }
//     return res;
// }


// dp
string s;
int f() {
    int f[26][226] = {0};
    f[0][0] = 1; // dp[i][sum] lưu số cách chia chuỗi từ vị trí i với tổng trước đó là sum
    for(int i = 0; i < s.length(); i++) {
        for(int prev = 0; prev < 226; prev++) {
            if(f[i][prev] == 0) { continue; }
            int cur = 0;
            for(int j = i; j < s.length(); j++) {
                cur = cur + (s[j] - '0');
                if(cur >= prev) {
                    f[j + 1][cur] += f[i][prev];
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 226; i++) {
        res = res + f[s.length()][i];
    }
    return res;
}

void solve() {
   int t = 0;
   while(cin >> s && s != "bye") {
    cout << ++t << ". " << f() << endl;
   }
}

int main(){
    faster();
    solve();
    return 0;
} 