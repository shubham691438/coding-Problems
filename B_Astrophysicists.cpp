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
     ll n, k, g;
        cin >> n >> k >> g;
        ll xx = k * g - (((g + 1) / 2) - 1) * n;
        if (xx < 0)
        {
            cout << k * g << endl;
        }
        else
        {
            ll zz = ((g + 1) / 2) - 1;
            ll yy = k * g - (((k * g - zz * n + g - 1) / g) * g);
            //    cout<<zz<<endl;
            cout << yy << endl;
        }
    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}