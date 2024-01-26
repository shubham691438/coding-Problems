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
    ll x;
    cin>>x;
    vector<ll> a(4);
    for(ll i=1;i<=3;i++) 
    {
        cin>>a[i];
    }

    ll key=x;
    if(a[key]==0)
    {
        cout<<"NO"<<endl;
        return;
    }

    key=a[key];

    if(a[key]==0)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}