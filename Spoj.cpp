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
//const int oo = inf;

void solve() {
    int n; cin >> n;
    vector<ii>a(n + 5);
    int f[2][10001];
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    f[1][1] = a[1].se; // nguoi dau luon lam tro li, va nguoi cuoi thi luon la co truong
    for(int i = 2; i <= n; i++) {
        int limit = min(i, n / 2);
        int ii = (i % 2);
        int prev = 1 - ii; // i - 1
        f[ii][0] = f[prev][1] + a[i].fi; // chinh 
        f[ii][limit] = f[prev][limit - 1] + a[i].se; // fu
        for(int j = 1; j < limit; j++) {
            f[ii][j] = min(f[prev][j - 1] + a[i].se, f[prev][j + 1] + a[i].fi);
        }
    }
    cout << f[0][0]; // f[n][0] : kết quả là fi công thứ i, khi còn 0 trợ lí chờ ghép
}

// F[i][j]: là tổng chi phí thấp nhất khi xét xong i phi công đầu tiên, trong đó còn j trợ lí chưa được ghép

// nếu chọn làm cơ trưởng : có ct : f[i][j] = f[i - 1][j + 1] + a[i].fi;
// ở fi công thứ i, nếu là cơ trưởng, thì => j sẽ giảm đi 1 == j - 1 => j + 1 giảm đi còn j
// vd : ở phi công thứ i, nếu ổng chọn làm cơ trưởng, thì => còn lại j fi công và để còn lại j fi công => f[i][j] = f[i - 1][j + 1] + a[i].fi;

// nếu chọn làm cơ phó: có ct : f[i][j] = f[i - 1][j - 1] + a[i].se;
// ở fi công thứ i, nếu là cơ phó, thì => j sẽ tăng lên 1 == j + 1 => j - 1 tăng lên = j
// vd : ở phi công thứ i, nếu ổng chọn làm cơ phó, thì => tăng lên j fi công và để tăng lên j fi công, => f[i][j] = f[i - 1][j - 1] + a[i].se;


int main(){
    faster();
    solve();
    return 0;
}