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

int main() {
    ll T;
    cin >> T;
    const ll BIG = 1e15+7;

    while (T--) {
        ll m, x;
        cin >> m >> x;

        vector<ll> c(m);
        vector<ll> h(m);

        for (ll i = 0; i < m; ++i) {
            cin >> c[i] >> h[i];
        }

        ll mh = 0;
        for (ll i = 0; i < m; ++i) {
            mh += h[i];
        }

        vector<ll> dp(mh + 1, BIG);

        //dp[hapiness]=cost
        dp[0] = 0;

        for (ll i = 0; i < m; ++i) {
            for (ll j = mh; j >= h[i]; --j) {
                if (dp[j - h[i]] + c[i] <= i * x) { 
                    dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
                }
            }
        }

        

        for (ll i = mh; i >= 0; --i) {
            if (dp[i] != BIG) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
