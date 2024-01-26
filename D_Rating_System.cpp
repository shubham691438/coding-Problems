// https://www.youtube.com/watch?v=jT3Hf9pxJzE
#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

 
    multiset<ll> s;
    ll postsum = 0;
    s.insert(postsum);
    for (ll i = n - 1; i >= 0; i--)
    {
        postsum += a[i];
        s.insert(postsum);
    }
 
    ll k = 0;
    ll presum = 0;
    ll mxans = *s.rbegin();
 
    for(ll i=0;i<n;i++)
    {
        presum += a[i];
        s.erase(s.find(postsum));
        postsum -= a[i];
        ll num = *s.rbegin();
 
        ll ans = presum + num;
 
        // cout << ans << ' ';
        if (ans > mxans)
        {
            mxans = ans;
            k = presum;
        }
    }
 
    cout << k << endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}