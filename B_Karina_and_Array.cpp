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

 
 bool checkZero(vector<ll> &a)
 {
    ll n=a.size();
    for(ll i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            return true;
        }
    }
    return false;

 }
void solve(){
    ll n;
    cin>>n;
    
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    sort(a.begin(),a.end());

    ll ans=max(a[0]*a[1],a[n-1]*a[n-2]);
    
    
    if(checkZero(a))
    {
        ll zero=0;
        ans=max(ans,zero);
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}