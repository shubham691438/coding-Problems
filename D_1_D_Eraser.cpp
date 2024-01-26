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

    string str;
    cin>>str;

    vector<int> indexes;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='B')
        indexes.push_back(i);
    }    

    int ans=0,curr=0;
    for(int i=0;i<indexes.size();i++)
    {
        if(indexes[i]>curr-1)
        {
            ans++;
            curr=indexes[i]+k;
        }
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}