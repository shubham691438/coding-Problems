#include<bits/stdc++.h>
using namespace std;
 
// DEBUG CODE 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



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
    char trump;
    cin>>trump;

    vector<string> a(2*n);
    for(auto &x: a) cin>>x;

    
    map<char,vector<ll>> mp;
    for(int i=0;i<2*n;i++)
    {
        mp[a[i][1]].push_back(a[i][0]-'0');
    }


    
    //defects
    ll defects=0;
    for(auto &ele:mp)
    {   
        sort(ele.second.begin(),ele.second.end());
        char c=ele.first;
        vector<ll> v=ele.second;

        if(c!=trump && v.size()%2==1)
            defects++;

    }

    // cout<<defects<<endl;
    // for(auto ele:mp)
    // {
    //     cout<<ele.first<<" --> ";
    //     for(auto &x:ele.second) cout<<x<<" ";
    //     cout<<endl;
    // }

    if(mp[trump].size()<defects || (mp[trump].size()-defects)%2==1 )
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

     for(auto &ele:mp)
    {
        char c=ele.first;
        vector<ll> v=ele.second;

        if(c!=trump)
        {
           
            for(int i=2;i<=v.size();i+=2)
            {
                cout<<v[i-2]<<c<<" "<<v[i-1]<<c<<endl;
            }

            if(v.size()%2==1)
            {
                cout<<v[v.size()-1]<<c<<" "<<mp[trump][0]<<trump<<endl;

                mp[trump].erase(mp[trump].begin());
            }
           
        }

    }

    for(int i=0;i<mp[trump].size();i+=2)
        cout<<mp[trump][i]<<trump<<" "<<mp[trump][i+1]<<trump<<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}