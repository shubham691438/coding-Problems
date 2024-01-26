#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000000
#define mod LLONG_MAX
#define endl "\n"
#define ff first
#define ss second
#define w(t) ll t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb push_back
/*-----------------------------------------------------------------------------------*/

void solve() {
    ll n;
    cin >> n;
    string str;
    cin >> str;

    string ans = "";
    int i = 0;
    while (i < n) {
        if ((str[i] == 'b' || str[i] == 'c' || str[i] == 'd') &&
            ((i + 3 < n && (str[i + 3] == 'b' || str[i + 3] == 'c' || str[i + 3] == 'd')) || i + 2 == n - 1)) {
            ans += str.substr(i, 3);
            ans += ".";
            i += 3;
        } else {
            ans += str.substr(i, 2);
            ans += ".";
            i += 2;
        }
    }

    ans.pop_back();
    cout << ans << endl;
}

int main() {
    fastio
    w(t) {
        solve();
    }
    return 0;
}
