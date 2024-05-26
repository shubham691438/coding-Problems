#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000007

vector<ll> adj[N];
vector<ll> vis(N, 0), color(N, 0),subtree_size(N, 0);
ll totalNodesVisited;

void Clear(ll n) {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
        color[i] = 0;
        totalNodesVisited=0;
        subtree_size[i] = 0;
    }
}

ll bfs(ll a, ll b,  ll &stepsB) {
    queue<vector<ll>> q;  // {node, who moves to this node, distance}
    q.push({a, 1, 0});    // 1 represents 'a', initial distance is 0
    q.push({b, 2, 0});    // 2 represents 'b', initial distance is 0
    vis[a] = 1;
    vis[b] = 2;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        ll node = curr[0];
        ll who = curr[1];
        ll dist = curr[2];

        for (auto child : adj[node]) {
            if (vis[child] == 0) {
                if (who == 1) {  // 'a' moves
                    vis[child] = 1;
                    q.push({child, 1, dist + 1});
                } else if (who == 2) {  // 'b' moves
                    stepsB = dist + 1;  // Update the steps taken by 'b'
                    vis[child] = 2;
                    q.push({child, 2, dist + 1});
                }
            } else if (vis[child] == 1 && who == 2) { // Handle the case where 'b' finds an already visited node by 'a'
                stepsB = dist + 1;  // Update the steps taken by 'b'
                return child; // First blue node
               
            } 
            else if (vis[child] == 2 && who == 1) { // Handle the case where 'a' finds an already visited node by 'b'
               
                    vis[child] = 1;
                    q.push({child, 1, dist + 1});
            }
        }
    }
    return -1; // If no blue node is found
}
void dfs(ll node, ll n, ll &stepsB) {
    
    vis[node] = 1;
    stepsB++;
    totalNodesVisited++;
    // cout<<"node "<<node<<endl;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, n, stepsB);
        }
    }
    if (totalNodesVisited < n)
        stepsB++;
}
ll dfs_subtree_size(ll node) {
    vis[node] = 1;
    subtree_size[node] = 1;  // Counting the node itself
    for (auto child : adj[node]) {
        if (!vis[child]) {
            subtree_size[node] += dfs_subtree_size(child);
        }
    }
    return subtree_size[node];
}



void solve() {
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;

    

    ll u, v;
    Clear(n);

    for (ll i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    
    ll stepsB;
    ll firstBlueNode;

    if(a==b)
    {
        stepsB=0;
        firstBlueNode=a;
    }
    else
    {
        stepsB=0;
        firstBlueNode = bfs(a, b,stepsB);
    }
    if (firstBlueNode != -1) {
        // cout <<"firstBlue Node "<<firstBlueNode << endl;
        // cout<<"stepb "<<stepsB<<endl;
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;  
        }

    // Call DFS to calculate subtree sizes
    dfs_subtree_size(firstBlueNode);
    
    // // Output the subtree sizes
    // cout << "Subtree sizes:" << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << "Node " << i << ": " << subtree_size[i] << endl;
    // }

    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end(),[&](int a,int b){
            return subtree_size[a]<subtree_size[b];
        });
    }

    for (int i = 1; i <= n; i++) {
            vis[i] = 0;  
        }
     
     
     dfs(firstBlueNode,n,stepsB);
     
     stepsB--;
     cout<<stepsB<<endl;

    } 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
