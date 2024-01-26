#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000007
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*-----------------------------------------------------------------------------------*/

 

void solve(){
  ll n,k; 
  cin>>n>>k;
    ll ans=1;
    for(ll i=0;i<n && k>1;i++,k--){
        ans=(ans*k)%mod;
    }
    cout<<ans<<endl;    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}