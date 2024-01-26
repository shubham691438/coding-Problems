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

    if(n<=6 || n==9)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(n%3==0)
    {
        cout<<"YES"<<endl;
        cout<<n-5<<" "<<4<<" "<<1<<endl;
    }    
    else
    {
        cout<<"YES"<<endl;
        cout<<n-3<<" "<<2<<" "<<1<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}