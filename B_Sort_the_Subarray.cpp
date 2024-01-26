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
    vector<ll> a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;  

    ll l,r;
    for(ll i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            l=i;
            break;
        }
    } 

    for(ll i=n-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            r=i;
            break;
        }
    }


    for(ll i=l-1;i>=0;i--)
    {
        if(b[i]<=b[i+1])
        {
            l=i;
        }
        else{
            break;
        }
    }

    for(ll i=r+1;i<n;i++)
    {
        if(b[i]>=b[i-1])
        {
            r=i;
            
        }
        else
        {
            break;
        }
    }

    cout<<l+1<<" "<<r+1<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}