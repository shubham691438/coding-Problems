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

    if(n&1)
    {
        cout<<-1<<endl;
        return;
    }

    for(int i=n;i>0;i--)
        cout<<i<<" ";

    cout<<endl;    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}