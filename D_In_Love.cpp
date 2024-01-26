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

void solve() {
    ll q;
    cin >> q;
    multiset<ll> left, right;
    while (q--) {
        char c;
        ll l, r;
        cin >> c >> l >> r;

        if (c == '+') {
            left.insert(l);
            right.insert(r);
        } else {
            left.erase(left.find(l));
            right.erase(right.find(r));
        }

        if(left.size()==0)
        {
            cout<<"NO"<<endl;
            
        }
        else if (*left.rbegin() > *right.begin()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    fastio
    solve();
    return 0;
}
