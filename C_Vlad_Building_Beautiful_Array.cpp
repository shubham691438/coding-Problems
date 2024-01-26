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

sort(a.begin(),a.end());
 if(a[0]&1){
    cout<<"YES"<<endl;
    return;
 }

 ll o=0,e=0;
 for(ll i=0;i<n;i++)
 {
    if(a[i]&1)
    {
        o++;
    }
    else
    {
        e++;
    }
 }    

 if(o>=1)
 {
    cout<<"NO"<<endl;
 }
 else{
    cout<<"YES"<<endl;
 }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}