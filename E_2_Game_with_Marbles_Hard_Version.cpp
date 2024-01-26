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
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n;
    cin>>n;

    vector<ll> a(n),b(n);
    for(auto &x:a ) cin>>x;
    for(auto &x:b)  cin>>x;

    multiset<pair<ll,ll>> st;
    for(ll i=0;i<n;i++)
    {
        st.insert({a[i]+b[i]-2,i});
    }    

    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        //alice chance
        if(i%2==0)
        {
           ll index= (*st.rbegin()).ss;
           st.erase(*st.rbegin());
           ans+=a[index]-1;

        }
        //bob chance
        else
        {
           ll index= (*st.rbegin()).ss;
           st.erase(*st.rbegin());
           ans-=b[index]-1;
        }
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}