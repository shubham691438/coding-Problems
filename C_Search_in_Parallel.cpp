#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n,t1,t2;
    cin>>n>>t1>>t2;

    multimap <ll,ll,greater<ll>> mp;
    for(ll i=1;i<=n;i++)
    {
        ll temp;
        cin>>temp;
        mp.insert(pair<ll,ll>(temp, i));
    }

    ll cnt1=0,cnt2=0;
    vector<ll> a,b;
    
    for(auto it:mp)
    {
        if(cnt1+t1<cnt2+t2)
        {
            a.push_back(it.ss);
            cnt1+=t1;
        }
        else
        {
            b.push_back(it.ss);
            cnt2+=t2;
        }
    }
    
    cout<<a.size()<<" ";
    for(ll i=0;i<a.size();i++)
        cout<<a[i]<<" ";

    cout<<endl;

    cout<<b.size()<<" ";
    for(ll i=0;i<b.size();i++)
        cout<<b[i]<<" ";

    cout<<endl;            
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}