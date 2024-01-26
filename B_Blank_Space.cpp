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

    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    ll cnt=0,blank=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            cnt++;
            blank=max(blank,cnt);
        }
        else
        {
            blank=max(blank,cnt);
            cnt=0;
        }
    }

    cout<<blank<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}