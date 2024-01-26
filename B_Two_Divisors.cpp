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

 //GCD
 ll gcd(ll a,ll b)
 {
       if(b==0)
            return a;
       else
            return gcd(b,a%b);
 }
 
void solve(){
    ll x,y;
    cin>>x>>y;

    ll lcm= x*y/gcd(x,y);

    if(lcm!=y) {
        cout<<lcm<<endl;
    }

    else
    {
        cout<<lcm*(y/x)<<endl;
    }


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}