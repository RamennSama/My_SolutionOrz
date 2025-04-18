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
const int inf = 1e5 - 2e3;
const int oo = inf;

vector<ll>preK;
vector<ll>pre;
vector<int>mp(inf * 2 + 1, 0);

void fil() {
    mp[0] = mp[1] = 1;
    for(int i = 2; i * i <= 2 * inf; i++) {
        if(mp[i] == 0) {
            for(int j = i * i; j <= 2 * inf; j += i) {
                mp[j] = 1;
            }
        }
    }
}

int valid(ll num) {
    if(num < pre.size()) return mp[num] == 0;
    for(ll i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void __init__() {
    fil();
    for(int i = 0; i <= inf * 2; i++) {
        if(!mp[i]) {
            pre.push_back(i);
        }
    }
    for(int i = 0; i < pre.size() - 1; i += 2) { 
        string npre = to_string(pre[i]) + to_string(pre[i + 1]);
        ll num = stoll(npre);
        if(valid(num)) {
            preK.push_back(num);
        }
    }
}

void solve() {
    __init__();
    int k; cin >> k;
    cout << preK[k - 1] << endl;
}

int main(){
    faster();
    solve();
    return 0;
}
