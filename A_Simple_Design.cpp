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
    ll x,k;
    cin>>x>>k ;

    for(ll i=x;i<=x+100;i++)
    {
        ll num=i;
        int sum=0;
        while(num)
        {
            sum+=num%10;
            num=num/10;
        }

        if(sum%k==0)
        {
            cout<<i<<endl;
            break;
        }
    }   
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}