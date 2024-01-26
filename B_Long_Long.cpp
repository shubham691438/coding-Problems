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
    vector<ll> a;
    ll sum=0;
    for(ll i=0;i<n;i++){
         cin>>arr[i];
         sum+=abs(arr[i]);
         if(arr[i]!=0)
            a.push_back(arr[i]);
    }
       

    n=a.size();
    if(n==0)
    {
        cout<<sum<<" "<<0<<endl;
        return;
    }

    ll cnt=0;
    if(a[0]<0)
        cnt=1;
    for(ll i=1;i<n;i++)
    {
        if(a[i-1]>0 && a[i]<0)
            cnt++;
    }  

    cout<<sum<<" "<<cnt<<endl;      
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}