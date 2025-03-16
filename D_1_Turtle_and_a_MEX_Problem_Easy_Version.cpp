#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 200100
#define endl "\n"
#define w(t) ll t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    ll n, m;
    cin >> n >> m;

    ll maxi = 0;
    while (n--) {
        ll l;
        cin >> l;

        vector<ll> vis(l + 5, 0);
        for (int i = 0; i < l; i++) {
            ll x;
            cin >> x;
            if (x <= l + 4)
                vis[x] = 1;
        }

        ll mex1 = 0;
        while (vis[mex1]) {
            mex1++;
        }

        vis[mex1] = 1;
        ll mex2 = mex1;
        while (vis[mex2]) {
            mex2++;
        }

        maxi = max(maxi, mex2);
    }

    if (m <= maxi) {
        cout << maxi * (m + 1) << endl;
    } else {
        ll ans = maxi * maxi;
        ans += (m - maxi + 1) * (maxi + m) / 2;
        cout << ans << endl;
    }
}

int main() {
    fastio;
    w(t) {
        solve();
    }
}
