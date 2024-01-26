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

    vector<ll> a(n),preSum(n,0);
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;

        if(i%2==0)
        {
            a[i]=temp;
        }
        else
        {
            a[i]=-temp;
        }
    }    

    map<ll,bool> sumMap;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];

        if(sum==0 || sumMap[sum]==true)
        {
            cout<<"YES"<<endl;
            return;
        }

        sumMap[sum]=true;    
    }

    cout<<"NO"<<endl;



}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}