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
    ll ans=n*4+n-1+3;

    ll num=(((n-2)*(n-1)/2)-1)*2;
    // for(ll i=2;i<=n-2;i++)    
    // {
    //     ans+=2*i;
    // }

    cout<<ans+num<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}