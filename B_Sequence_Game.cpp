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

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    vector<int> ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++)
    {   
        // cout<<"check : "<<a[i]<<" "<<a[i-1]<<endl;
        if(a[i]<a[i-1])
        {
            ans.push_back(a[i]);
            ans.push_back(a[i]);
        }
        else
            ans.push_back(a[i]);    
    }  
    
    cout<<ans.size()<<endl;
    for(auto &x:ans) cout<<x<<" ";
    cout<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}