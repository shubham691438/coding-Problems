#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll power(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a == 1) {
        // If a is 1, the sequence is 1, 1, 1, 1, ...
        // We need to check if (n-1) is divisible by b
        if ((n - 1) % b == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return;
    }

    ll current = 1;
    while (current <= n) {
        if ((n - current) % b == 0) {
            cout << "Yes" << endl;
            return;
        }
        current *= a;
        if (current > n) break; // To prevent overflow
    }

    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
