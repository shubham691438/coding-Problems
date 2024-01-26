#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      mod        1000000000000000007
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll x,y;
    cin>>x>>y;
    
    ll val1=( ( ( ( ( (x*x)%mod)*x)%mod)*x)%mod + (4ll*((y*y)%mod))%mod)%mod;
    
    ll val2=(((4*x)%mod)*((x*y)%mod))%mod;
    
    if(val1==val2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}