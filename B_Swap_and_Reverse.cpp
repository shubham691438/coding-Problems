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
    ll n,k;
    cin>>n>>k;

    string str;
    cin>>str;

    vector<char> evens,odds;
    for(int i=0;i<n;i++)
    {
        if(i%2==0) evens.push_back(str[i]);
        else odds.push_back(str[i]);
    }    

    sort(evens.begin(),evens.end());
    sort(odds.begin(),odds.end());
    string ans="";
    for(int i=0,j=0;i<evens.size() || j<odds.size();i++,j++)
    {
        if(i<evens.size()) ans+=evens[i];
        if(j<odds.size()) ans+=odds[i];
    }

    if(k%2==0) sort(ans.begin(),ans.end());

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}