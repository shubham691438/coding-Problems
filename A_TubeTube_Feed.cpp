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
    ll n,tim;
    cin>>n>>tim;

    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(ll i=0;i<n;i++)
    {
        a[i]=i+a[i];
    }
    
    for(ll i=0;i<n;i++)
        cin>>b[i];

    int ans = -1;
    for (int i=0; i<n;i++)
    {
        if(a[i]<=tim)
        {
            if(ans==-1 || b[i]>b[ans])
            {
                ans=i;
            }
        }
    }

    if(ans==-1)
    {
        cout<<-1<<endl;
        return;
    }

    cout<<ans+1<<endl;



}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}