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

    vector<ll> arr(n);
    for(auto &x:arr) cin>>x;

    vector<ll> a=arr;
    sort(a.begin(),a.end());
    vector<ll> pre(n,0),post(n,0);
    pre[0]=a[0],post[n-1]=a[n-1];
    for(ll i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    } 
    for(ll i=n-2;i>=0;i--)
    {
        post[i]=post[i+1]+a[i];
    }   


    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {   
        if(i+1<n)
            v[i]=n+a[i]*(2*(i+1)-n)-pre[i]+post[i+1];
        else
            v[i]=n+a[i]*(2*(i+1)-n)-pre[i]+0;
    }

    map<ll,ll> mp;
    for(ll i=0;i<n;i++)
    {
        mp[a[i]]=v[i];
    }

    for(ll i=0;i<n;i++)
        cout<<mp[arr[i]]<<" ";
     cout<<endl;   

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}