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
        ll n,k;
        cin>>n>>k;
        if(k==1)
        {
             cout<<n<<endl;
             return;
        }
        if(n%k)
        {
            if(n%k==1)
            {
                cout<<(n/k)+1<<endl;
            }
            else 
            {
                 cout<<(n/k)+2<<endl;
            }
        }
        else 
        {
            cout<<n/k+1<<endl;
        }    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}