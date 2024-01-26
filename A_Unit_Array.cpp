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
    int cnt1=0,cnt2=0;
    for(auto &x:a){
         cin>>x;
        if(x==-1)
            cnt1++;
        else
            cnt2++;    
    }

    int ans=0;

    while((-cnt1 + cnt2) <0 || cnt1%2!=0)
    {
        cnt1--;
        cnt2++;
        ans++;
    }

    cout<<ans<<endl;
    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}