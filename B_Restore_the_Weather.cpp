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
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    vector<ll> c(n);
    for(ll i=0;i<n;i++)
    {
        c[i]=a[i];
    }
    multimap<ll,ll> mp;
    // for(auto ele:a)
    // {
    //     mp.insert({ele,0});
    // }  

    sort(b.begin(),b.end()); 
    sort(c.begin(),c.end());  
    
    for(ll i=0;i<n;i++)
    {
        // cout<<c[i]<<" "<<b[i]<<endl;
        mp.insert({c[i],b[i]});
    }

    for(ll i=0;i<n;i++)
    {
        auto it = mp.find(a[i]);
        cout<<it->second<<" ";
        mp.erase(it);
    }

    cout<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}