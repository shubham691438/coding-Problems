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
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/


void dfs(ll node,vector<ll> adj[],vector<ll> &vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
 
 
void solve(){
    ll n;
    cin>>n;
    
   

    vector<vector<ll>> grp(n-1,vector<ll>(2));
    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        grp[i][0]=u-1;
        grp[i][1]=v-1;
    }

     if(n<=2){
        cout<<0<<endl;
        return;
    }
    
    vector<ll> adj[n];
    for(int i=0;i<n-1;i++){
        adj[grp[i][0]].pb(grp[i][1]);
        adj[grp[i][1]].pb(grp[i][0]);
    }

    int maxi=0,t=0;
    for(int i=0;i<n-1;i++){
        if(adj[i].size()>maxi){
            maxi=adj[i].size();
            t=i;
        }
    }

    vector<ll> adj1[n];
    for(int i=0;i<n-1;i++)
    {
        if(grp[i][0]==t || grp[i][1]==t) continue;
        
        adj1[grp[i][0]].pb(grp[i][1]);
        adj1[grp[i][1]].pb(grp[i][0]);
        
    }

    // for(int i=0;i<n;i++){
    //    cout<<i+1<<"->";
    //      for(auto it:adj1[i]){
    //           cout<<it+1<<" ";
    //      }
    //         cout<<endl;
    // }

    int maxi1=0,t1=0;
    for(int i=0;i<n-1;i++){
        if(adj1[i].size()>maxi1){
            maxi1=adj1[i].size();
            t1=i;
        }
    }

    vector<ll> adj2[n];
    for(int i=0;i<n-1;i++)
    {
        if(grp[i][0]==t || grp[i][1]==t || grp[i][0]==t1 || grp[i][1]==t1) continue;
        
        adj2[grp[i][0]].pb(grp[i][1]);
        adj2[grp[i][1]].pb(grp[i][0]);
        
    }

    //  for(int i=0;i<n;i++){
    //    cout<<i+1<<"->";
    //      for(auto it:adj2[i]){
    //           cout<<it+1<<" ";
    //      }
    //         cout<<endl;
    // }

    // cout<<"T1 And T2 "<<t+1<<" "<<t1+1<<endl;

    vector<ll> vis(n,0);
    int cc=0;
    for(int i=0;i<n;i++){
        if(!vis[i] && i!=t && i!=t1){
             cc++;
            dfs(i,adj2,vis);
           
        }
        
    } 

    cout<<cc<<endl;

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}