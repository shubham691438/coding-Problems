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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll prod=1;
    for(ll i=0;i<n;i++) 
    {
        cin>>a[i];
        prod*=a[i];
    }  

    if(2023%prod != 0)
    {
        cout<<"NO"<<endl;
    }  
    else
    {
        cout<<"YES"<<endl;
        cout<<2023/prod<<" ";
        for(int i=0;i<k-1;i++)
        {
            cout<<1<<" ";
        }

        cout<<endl;
    }

    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}