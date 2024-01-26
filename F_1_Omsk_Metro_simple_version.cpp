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

vector <pair<ll,ll>> adj[N];
vector <ll>vis(N,0),dis(N,-1);

void Clear(ll n)
{
 for(int i=1;i<=n;i++)
 {
     adj[i].clear();
     vis[i]=0;
 }

}


// void dfs(ll node )
// {
//  vis[node]=1;
//  for(auto child:adj[node])
//  {
//        if(!vis[child])
//           dfs(child);
//  }
// }

int v;
bool first;
void addToTree()
{   
    int u,w;
    cin>>u>>w;
    
    if(first)
    {
        adj[v].push_back({u,w});
        adj[u].push_back({v,1})
    }
}

void answerQuestion()
{

}

void solve(){

    v=1;
    first=true;

    ll q;
    cin>>q;
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='+')
            addToTree();
        else
            answerQuestion();
    }

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}
