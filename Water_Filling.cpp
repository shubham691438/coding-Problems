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
 int a,b,c;
 cin>>a>>b>>c;

 int sum=a+b+c;
 if(sum<=1)
 {
    cout<<"Water filling time"<<endl;
 }    
 else
 {
    cout<<"Not now"<<endl;
 }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}