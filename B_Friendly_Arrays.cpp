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
ll n, m; cin >> n >> m;
 
        ll xx = 0;
 
        ll xr = 0;
 
        vector <ll> a (n), b (m);
 
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            xr = (xr ^ a[i]);
        }
 
        for (ll i = 0; i < m; i++) {
            cin >> b[i];
            xx |= b[i];
        }
 
        if (n % 2 == 0) {
            cout << (xr & (~xx)) << " " << xr << endl;
        }
        else {
            cout << (xr) << " " << (xr | xx) << endl;
        }    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}