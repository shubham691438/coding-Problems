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
    ll n,k,x;
    cin>>n>>k>>x;

    if(k>x+1 || n<k)
    {
        cout<<-1<<endl;
        return;
    }    

    if(k==x)
        cout<< k*(k-1)/2 + (n-k)*(x-1)<<endl;
    else    
    cout<< k*(k-1)/2 + (n-k)*x<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}