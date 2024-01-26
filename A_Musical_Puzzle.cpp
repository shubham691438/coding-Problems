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
 ll n;
 cin>>n;

 string str;
 cin>>str;

unordered_set<string> st;
 for(ll i=0;i<n-1;i++)
 {
    st.insert(str.substr(i,2));
 }    

// for(auto ele:st)
// {
//     cout<<ele<<" ";
// }
// cout<<endl;
 cout<<st.size()<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}