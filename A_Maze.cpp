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

bool is_possible(ll r,ll c, vector<vector<char>> &adj ) 
{
    if(r<0 || c<0 || r>=adj.size() || c>= adj[0].size()) return false;
    if( adj[r][c] =='#') return false;

    return true;
}
 
void solve(){
   ll n,m,k;
   cin>>n>>m>>k;

   vector<vector<char>> adj(n,vector<char>(m)); 
   vector<vector<ll>> vis(n,vector<ll>(m,0)); 

    queue<pair<ll,ll>> q;

    vector<pair<ll,ll>> bfsArray;
  
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        cin>>adj[i][j];
        if(adj[i][j]=='.' && q.empty())
        {
            q.push({i,j});
            vis[i][j]=true;
            bfsArray.push_back({i,j});
        }
    }
   }

   while(!q.empty())
   {
     ll r_curr=q.front().first;
     ll c_curr= q.front().second;
     q.pop();

     vector<ll> rDir={-1,1,0,0};
     vector<ll> cDir={0,0,-1,1};

     for(int i=0;i<4;i++)
     {
        ll r= r_curr+ rDir[i];
        ll c= c_curr + cDir[i];
        if(is_possible(r,c,adj) && !vis[r][c])
        {
            vis[r][c]=1;
            q.push({r,c});
            bfsArray.push_back({r,c});
        }
     }  


     

   }

   reverse(bfsArray.begin(),bfsArray.end());

     for(int i=0;i<k;i++)
     {
        adj[bfsArray[i].first][bfsArray[i].second]='X';
     }


     for(int i=0;i<n;i++)       
     {
        for(int j=0;j<m;j++)
        {
            cout<<adj[i][j];
        }

        cout<<endl;
     }

    cout<<endl;
       
   

}
 
 
int main(){
    fastio;
    
        solve();
    
}