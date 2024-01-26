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

bool check(vector<ll> &a,ll h,ll x)
{
    ll n=a.size();
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        if(h>a[i])
        {
            cnt+=h-a[i];
        }
    }
    
    // cout<<"cnt "<<cnt<<endl;
    return cnt<=x;

}
 
 
void solve(){
    ll n,x;
    cin>>n>>x;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];

    ll l=0,r=INT_MAX,mid;

    ll ans=1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        // cout<<mid<<endl;
        if(check(a,mid,x))
        {
            ans=mid;
            l=mid+1;
            
        }
        else
        {
            r=mid-1;
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