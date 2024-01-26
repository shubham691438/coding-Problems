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
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for(auto &x: a) cin>>x;

    vector<ll> sorted(n);
    for(int i=1;i<n;i++)
        sorted.push_back(abs(a[i]-a[i-1]));

    sort(sorted.begin(),sorted.end(),greater<ll>());

    ll sum=0;
    for(int i=k-1;i<n;i++){
        // cout<<sorted[i]<<" ";
        sum+=sorted[i];
    }
        

    
    cout<<sum<<endl;


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}