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
    ll n,m;
    cin>>n>>m;

    for(int i=1;i<=n/2;i++)
    {
        
        if((2*(i+m))%4 !=0 && (2*(n-i+m))%4!=0)
        {
           
            cout<<"YES"<<endl;
            return;
        }
        
    }  

    for(int i=1;i<=m/2;i++)
    {
        
        if((2*(i+n))%4 !=0 && (2*(m-i+n))%4!=0)
        {
           
            cout<<"YES"<<endl;
            return;
        }
        
    }  

    cout<<"NO"<<endl;  
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}