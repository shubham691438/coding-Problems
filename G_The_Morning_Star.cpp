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
    cin >> n;
    map<ll, ll> up, side, diag1, diag2;
    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        up[x]++;
        side[y]++;
        diag1[x-y]++;
        diag2[x+y]++;
    }
    for(auto x : up)
    {
        ans+=x.second*(x.second-1);
    }
    for(auto x : side)
    {
        ans+=x.second*(x.second-1);
    }
    for(auto x : diag1)
    {
        ans+=x.second*(x.second-1);
    }for(auto x : diag2)
    {
        ans+=x.second*(x.second-1);
    }
    cout << ans << endl;    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}