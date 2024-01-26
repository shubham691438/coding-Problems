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
    ll x,y,n;
    cin>>x>>y>>n;

    int min_diff=n*(n-1)/2;

    if(y-x<min_diff)  
    {
        cout<<-1<<endl;
        return;
    }  

    vector<int> ans;
    ans.push_back(y);
    int curr=y;
    for(int i=1;i<n-1;i++)
    {
        curr=curr-i;
        ans.push_back(curr);
    }

    ans.push_back(x);

    reverse(ans.begin(),ans.end());

    for(auto &x:ans)
    {
        cout<<x<<" ";
    }

    cout<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}