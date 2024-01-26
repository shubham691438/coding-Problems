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

void dfs(ll node )
{
	vis[node]=1;
	for(auto child:adj[node])
	{
		if(!vis[child]){
            if()
            dfs(child);
        }
			
	}
}


void solve(){
    ll n,m ;
	cin>>n>>m;	// n=nodes m=edges
	ll u,v;
	Clear(n);

	for(ll i=1;i<=m;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}

    dfs(1);
    

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}
