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
    
    int ans=0;
    int mini=n+1,miniWIN=n+1;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;

        if(mini<p && miniWIN>p)
        {
            ans+=1;
            miniWIN=p;
        }

        mini=min(mini,p);
    }

    cout<<ans<<endl;


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}