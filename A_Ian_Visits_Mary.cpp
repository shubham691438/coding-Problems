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
    ll a,b;
    cin>>a>>b;

    if(a==1&& b==1)
    {
        cout<<1<<endl;
        cout<<a<<" "<<b<<endl;
        return;
    }
    // if(b%a!=0)
    // {
    //     cout<<1<<endl;
    //     cout<<a<<" "<<b<<endl;
    //     return;
    // }
    else{
        cout<<2<<endl;
        cout<<a-1<<" "<<1<<endl;
        cout<<a<<" "<<b<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}