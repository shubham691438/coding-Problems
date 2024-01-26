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
    vector<int> a(n);
    for(auto &x:a ) cin>>x;

    map<int,int> freq;
    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;
    }    
    
    cout<<"freq "<<endl;
    for(auto ele:freq)
    {
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    cout<<"end"<<endl;
    map<double,int> mp;
    for(int i=0;i<n;i++)
    {
        if(floor(a[i]-log2(a[i]))==a[i]-log2(a[i]))
            mp[ a[i]-log2(a[i]) ]+=freq[a[i]];
    }

    ll ans=0;
    unordered_set<double> vis;

    for(auto ele:freq)
    {
        ll num=ele.first;
        ll m=freq[num];
        ans+=m*(m-1)/2;

        
        if(vis.find(num-log2(num))==vis.end() && mp.find(num-log2(num))!=mp.end()){
            cout<<num-log2(num)<<" "<<mp[num-log2(num)]<<endl;
            ans+= mp[num-log2(num)]-freq[num];
            vis.insert(num-log2(num));
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