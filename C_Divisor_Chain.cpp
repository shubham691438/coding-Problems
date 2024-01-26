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

#define all(a) (a).begin(), (a).end()
#define pb push_back


bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}
 
 
void solve(){
    int x;
        cin >> x;
        int p;
        vector<int> ans;
        ans.pb(x);
        for (int i = 0; ; ++i) {
            if (bit(x, i)) {
                if (x == (1 << i)) {
                    p = i;
                    break;
                }
                x -= (1 << i);
                ans.pb(x);
            }
        }
        while (p > 0) {
            x -= (1 << (p - 1));
            ans.pb(x);
            --p;
        }
        cout << ans.size() << "\n";
        for (int y : ans) {
            cout << y << " ";
        }
        cout << "\n";
    }    

 
 
int main(){
    fastio
    w(t){
        solve();
    }
}