#include <bits/stdc++.h>
using namespace std;

#define      ll         long long
#define      MAX        1000000
#define      endl       "\n"
#define      N          1000007
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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

vector <ll> adj[N];
vector <ll>vis(N,0),dis(N,-1);

void Clear(ll n)
{
 for(int i=1;i<=n;i++)
 {
     adj[i].clear();
     vis[i]=0;
 }

}

void bfs(ll src)
{
 queue<ll> q;
 vis[src]=1;
 dis[src]=0;
 q.push(src);

 while(!q.empty())
 {
     
     int curr=q.front();
     q.pop();
     cout<<curr<<endl;
     for(auto child:adj[curr])
     {
         if(!vis[child])
         {
             vis[child]=1;
             dis[child]=dis[curr]+1;
             q.push(child);
         }
         
     }
 }
}

ll dfs(ll node ,ll x,ll &cuts)
{
 vis[node]=1;
 ll sz=1;
 for(auto child:adj[node])
 {
       if(!vis[child])
       {
         sz+= dfs(child,x,cuts);
       }
         
 }

 if(sz>=x) sz=0,cuts++;

 return sz;
}

bool ok(ll x,ll k,ll n)
{
    ll cuts=0;
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    dfs(1,x,cuts);

    return cuts > k;
}


void solve(){
 ll n,m,k ;
 cin>>n>>k;  
 m=n-1;

 ll u,v;
 Clear(n);

 for(ll i=1;i<=m;i++)
 {
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);

 }

  
  ll l=0,r=n;
  ll ans=0;

  while(l<=r)
  {
    ll mid= l+(r-l)/2;

    
    
    if(ok(mid,k,n))
    {   
        ans=mid;
        l=mid+1;
    }
    else
    {
        r=mid-1;
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
