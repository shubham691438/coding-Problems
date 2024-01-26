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
    ll n;
    cin>>n;

    string s;
    cin>>s;

    map<char,int> mp;
    for(int i=0;i<n;i++) mp[s[i]]++;

    int ans=0;

    for(auto ele:mp)
    {
        if(ele.second>=ele.first-'A'+1)
            ans++;
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}