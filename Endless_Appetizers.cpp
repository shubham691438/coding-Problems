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
    ll x,y,r;
    cin>>x>>y>>r;

    int extra=r/30;
    int eaten=x+extra;

    if(eaten%y==0)
    {
        cout<<eaten/y<<endl;
    }   
    else
    {
        cout<<eaten/y+1<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}