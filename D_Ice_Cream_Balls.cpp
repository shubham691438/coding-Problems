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


ll find( ll n)
{
    return n* (n-1)/2;
} 
 
void solve(){
    ll n;
    cin>>n;

    ll l=0,r=2e9;
    ll ans=l;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(find(mid)<=n)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    
    ans+=n-find(ans);

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}