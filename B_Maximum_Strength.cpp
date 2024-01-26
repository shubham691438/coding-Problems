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
  string strL, strR;
    cin>>strL >> strR;
    int lenR = strR.size();
    if (strR.size() > strL.size())
    
        cout << strR[0] - '0' + 9 * (lenR - 1) << endl;
    else {
        for (int i = 0; i < lenR; i++) {
            if (strR[i]!= strL[i]) {
                cout << strR[i] - strL[i] + 9 * (lenR - i - 1) << endl;
                return;
            }
        }
        cout << 0 << endl;
    }    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}