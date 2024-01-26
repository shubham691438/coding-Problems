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
    ll n,k;
    cin>>n>>k;

    vector<int> ans;
    for(int i=1;i<=k;i++)
        ans.push_back(i);

    for(int i=n;i>k;i--)
    {
        ans.push_back(i);
    }       

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    cout<<endl;    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}