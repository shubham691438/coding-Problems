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

ll sum(ll n)
{
    return n*(n+1)/2;
}
 
void solve(){
    ll n,x,y;
    cin>>n>>x>>y;

    ll lcm=x*y/gcd(x,y);

    
    ll no_commons=n/lcm;

    ll no_x=n/x-no_commons;
    ll no_y=n/y-no_commons;
    
    cout<<(sum(n)-sum(n-no_x)) - sum(no_y) <<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}
