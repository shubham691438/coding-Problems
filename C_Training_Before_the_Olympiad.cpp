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
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<ll> ans(n);
    ll even=0,odd=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(a[i]&1)
        {
            odd++;
        }
        else
        {
            even++;
        }

        if(i==0) ans[i]=a[i];
        else if(odd%3==1)
        {
            ans[i]=sum-odd/3-1;
        }
        else
        {
            ans[i]= sum-odd/3;
        }
        
    }    

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}