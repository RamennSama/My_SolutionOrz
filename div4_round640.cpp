#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fi first
#define se second
#define ed cout << "\n"
#define mem(a,b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define sz(A) (int) A.size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 1e5 + 15;

void check() {
    cout << "component scanning\n";
}

// A. Sum of Round Numbers
void solve() {
    int n; cin >> n;
    vector<int>nums;
    while(n) {
        nums.push_back(n % 10);
        n = n / 10;
    }
    reverse(all(nums));
    int z = count(all(nums), 0);
    cout << nums.size() - z << endl;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) continue;
        cout << to_string(nums[i]) + string(nums.size() - i - 1, '0') << ' ';
    }
    ed;
} 

// B. Same Parity Summands
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>nums;
    int ok = 1;
    if(n < k) ok = 0;
    if(n >= k && (n - (k - 1)) % 2 == 1) {
        while(k != 1) {
            nums.push_back(1);
            k--;
        } 
        nums.push_back(n - nums.size());
    } else if(n >= 2 * k && (n - ((k - 1) * 2)) % 2 == 0) { 
        while(k != 1) {
            nums.push_back(2);
            k--;
        } 
        nums.push_back(n - (nums.size() * 2));
    } else {
        ok = 0;
    }
    if(!ok) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int x : nums) {
            cout << x << ' ';
        }
        ed;
    }
} 

// C. K-th Not Divisible by n
void solve() {
    int n, k;
    cin >> n >> k;
    ll l = 1, r = 2e18, ans = 0;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        ll cnt = mid - mid / n; 
        if(cnt >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

// D - Alice, Bob and Candies
void solve() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int turn = 0, l = 0, r = n - 1;
    vector<int>alice(1, 0), bob(1, 0);
    int ta = 0, tb = 0;
    while(l <= r) {
        ta = tb = 0;
        while(l <= r && ta <= bob.back()) {
            ta = ta + a[l]; l++;
        }
        alice.push_back(ta);
        if(ta > 0) turn++;
        while(l <= r && tb <= alice.back()) {
           tb = tb + a[r]; r--;
        }
        bob.push_back(tb);
        if(tb > 0) turn++;
    }
    cout << turn << ' ' << accumulate(all(alice), 0) << ' ' << accumulate(all(bob), 0) << endl;
}

// E - Special Elements
void solve() {
    int n, ans = 0; cin >> n;
    int freq[8002] = {0}, a[n];
    for(int i = 0; i < n; i++) cin >> a[i], freq[a[i]]++;
    vector<int>f(a, a + n);
    for(int i = 1; i < n; i++) f[i] += f[i - 1];
    auto get = [&](int l, int r) -> int {
        return l == 0 ? f[r] : f[r] - f[l - 1];
    };
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int cur = get(l, r);
            if (cur > n) continue; 
            if (freq[cur] > 0) {
                ans += freq[cur];
                freq[cur] = 0;
            }
        }
    }
    cout << ans << endl;
}

// F - Binary String Reconstruction
void solve() {
    int n1, n2, n3, ok = 1;
    cin >> n1 >> n2 >> n3;
    string _00 = "", _11 = "", ans = "";
    if(n1 > 0) _00 = string(n1 + 1, '0');
    if(n3 > 0) {
        _11 = string(n3 + 1, '1');
        if(!_00.empty()) ok = 0;
    }
    ans = _00 + _11;
    if(ans.empty()) ans = "0";
    char last = ans.back();
    if(!ok) n2 -= 1;
    for (int i = 0; i < n2; ++i) {
        last = (last == '0') ? '1' : '0';
        ans += last;
    }
    cout << ans << endl;
}

// G - Special Permutation
void solve() {
    int n; cin >> n;
    vector<int> ans, odd, even, ans_;
    if(n <= 3) {
        cout << -1 << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) odd.push_back(i);
            else even.push_back(i);
        }
        if(n % 2 == 0) swap(odd[odd.size() - 2], odd[odd.size() - 1]);
        else swap(even[even.size() - 2], even[even.size() - 1]);
        for(int i = 0; i < odd.size(); i++) cout << odd[i] << ' ';
        for(int i = even.size() - 1; i >= 0; i--) cout << even[i] << ' ';
        ed;
    }
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
