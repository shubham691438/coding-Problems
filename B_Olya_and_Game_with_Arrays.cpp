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

    vector<ll> second_mini;
    ll mini=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        ll m;
        cin>>m;
        vector<ll> a(m);
        
        for(auto &x:a) cin>>x;

        sort(a.begin(),a.end());

        mini=min(a[0],mini);
        
        second_mini.push_back(a[1]);

    }    
    ll sum=0;
    for(auto &x:second_mini) sum+=x;
    ll ans=0;
    for(auto &x:second_mini)
    {
        ans=max(ans,sum-x+mini);
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}