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
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }    

    sort(a.begin(),a.end(),greater<ll>());
    for(int i=1;i<n;i++)
    {
        a[i]=a[i]+a[i-1];
    }

    for(int i=n-1;i>=0;i--)
        cout<<a[i]<<" ";

    cout<<endl;    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}