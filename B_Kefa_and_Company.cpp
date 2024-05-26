#include <bits/stdc++.h>
using namespace std;

// DEBUG CODE
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ll long long
#define MAX 1000000
#define mod LLONG_MAX
#define endl "\n"
#define ff first
#define ss second
#define w(t) ll t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(a) (a).begin(), (a).end()
#define pb push_back
/*-----------------------------------------------------------------------------------*/

bool compare(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    if (a.first < b.first) return true;
    if (a.first == b.first) return a.second > b.second;
    return false;
}

ll bs(vector<pair<ll,ll>> &a, ll num) {
    ll l = 0, r = a.size() - 1; // Fix the right bound to size() - 1
    ll ans = a.size(); // Initially set to size (out of bounds)
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (a[mid].first < num) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), compare);

    // debug(a);
    vector<ll> preSum(n);
    preSum[0] = a[0].second;
    for (int i = 1; i < n; i++)
        preSum[i] = preSum[i - 1] + a[i].second;

    ll maxi = 0;
    for (int i = 0; i < n; i++) {
        ll index = bs(a, a[i].first + d);
        // Ensure index is within bounds
        if (index < n) {
            maxi = max(maxi, i > 0 ? preSum[index - 1] - preSum[i - 1] : preSum[index - 1]);
        } else {
            maxi = max(maxi, preSum[n - 1] - (i > 0 ? preSum[i - 1] : 0));
        }
    }

    cout << maxi << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}
