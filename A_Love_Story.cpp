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
 string str1="codeforces", str2;
 cin>>str2;
 ll cnt=0;
 for(ll i=0;i<10;i++)
 {
    if(str1[i]!=str2[i])
    {
        cnt++;
    }
 }    

 cout<<cnt<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}