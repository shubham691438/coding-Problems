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

 bool check(ll n,ll m)
 {  

    if(n%3==0)
    {
        if(n/3==m || 2*(n/3)==m)
        {
            return true;
        }
        
        if(check(n/3,m))
        {
            return true;
        }

        if(check(2*n/3,m))
        {
            return true;
        }
    }
    

    return false;
 }
 
void solve(){
    ll n,m ;
    cin>>n>>m;

    if(n==m)
    {
        cout<<"YES"<<endl;
        return;
    }
    
    if(check(n,m))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}