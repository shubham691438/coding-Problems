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
    ll x,y,k;
    cin>>x>>y>>k;

    if(x>=y){
        cout<<x<<endl;
    }    
    else
    {
        cout<<y+max(y-(x+k),(ll)0)<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}