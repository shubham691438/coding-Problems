#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MarrX        1000000
#define      mod        LLONG_MarrX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n;
    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
        return;
    }
    
    if(n%2==1){
        cout<<"-1"<<endl;
        return;
    }

    vector<ll> arr;
    for (ll i = 0; i < n / 2; i++) {
        arr.push_back(i);
        arr.push_back(n - i - 1);
    }

    
    vector<ll> ans(n);
     ans[0]=n;
    for (ll i = 0; i < n - 1; i++) {
        
        ans[i+1]=(arr[i + 1] - arr[i] + n) % n ;
    }

    for(ll i=0;i<n;i++)
        cout<<ans[i]<<" ";

    cout<<endl;     
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}