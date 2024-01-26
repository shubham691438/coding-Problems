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
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    if(n==1)
    {
        if(a[0]<0) 
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<a[0]<<endl;
        }

        return ;
    }        


    ll ans=0;
    if(a[0]>=0 || (a[0]<=0 && a[1]<=0))
    {
        for(int i=0;i<n;i++)
            ans+=max(0ll,a[i]);

        cout<<ans<<endl;    
    }

    else
    {
        ans+=max(0ll,a[0]+a[1]);
        for(int i=2;i<n;i++)
            ans+=max(0ll,a[i]);

        cout<<ans<<endl;    
    }

    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}