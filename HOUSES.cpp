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

int L, N, cnt = 0;
int a[21], used[21] = {0};
int r[101] = {0};
int sold, notsold;

void print() {
    cnt++;
    for(int i = 1; i <= L; i++) {
        cout << r[i] << ' ';
    }
    ed;
}
// dk : luon ban can nha dau tien pos > 1
void f(int pos, int ignore ) {
    if(cnt == 1000) {
        exit(0);
    }
    if(pos == L + 1) {
        print();
        return;
    }

    if (pos > 1 && ignore < notsold) f(pos + 1, ignore + 1);  // chua lai 1 can nha, ko ban

    for(int i = 1; i <= N; i++) {
        if(!used[i]) {
            
            used[i] = 1;
            for(int j = 0; j < a[i]; j++) {
                r[pos + j] = i;
            }

            f(pos + a[i], ignore);

            used[i] = 0;
            for(int j = 0; j < a[i]; j++) {
                r[pos + j] = 0;
            }
        }
    }
}

void solve() {
    cin >> L >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        sold = sold + a[i];
    }
    notsold = L - sold; // ko pan
    f(1, 0);
}

int main(){
    faster();
    solve();
    return 0;
}