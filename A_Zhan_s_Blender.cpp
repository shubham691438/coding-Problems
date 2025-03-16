#include<bits/stdc++.h>
using namespace std;
 



#define      ll         long long
#define      MAX        1000000
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    int n;
    cin>>n;

    int x,y;
    cin>>x>>y;

    int mini=min(x,y);
    cout<< (n+mini-1)/mini <<endl;

   
    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}