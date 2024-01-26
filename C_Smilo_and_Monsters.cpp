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
    for(auto &x:a) cin>>x;

    sort(a.begin(),a.end());
    ll ans=0;
    ll l=0,r=n-1,x=0;
    while(l<=r)
    {
        if(l==r){
            
            if(a[r]<=1) {
                ans+=a[r];
                break;
            }
            ll firstType=(a[r]-x+1)/2;
            ans+=firstType+1;
            break;
        }

        ll firstType=min(a[l],a[r]-x);
        x+=firstType;
        a[l]-=firstType;
        ans+=firstType;

        if(a[l]==0) l++;

        if(x==a[r]) {
            r--;
            ans++;
            x=0;
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