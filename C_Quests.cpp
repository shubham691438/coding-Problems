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
    ll n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int ans=0;
    int b_max=0,sum=0;
    for(int i=0;i<min(n,k);i++)
    {
        sum+=a[i];
        b_max=max(b_max,b[i]);

        ans=max((ll)ans,sum+ (k-i-1)*b_max );
    }

    cout<<ans<<endl;
}

int main() {
    fastio
    w(t) {
        solve();
    }
}
