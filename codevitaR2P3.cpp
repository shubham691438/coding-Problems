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

bool isValid(int r, int c, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &mat) {
    if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && mat[r][c] == 0)
        return true;

    return false;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    vector<int> src(2), target(2), rule(2);
    cin >> src[0] >> src[1];        
    cin >> target[0] >> target[1];        
    cin >> rule[0] >> rule[1];

    int dr[] = { 1, 1, -1, -1 };
    int dc[] = { 1, -1, 1, -1 };

    queue<pair<int, int>> q;
    vector<vector<int>> dis(n, vector<int>(m, 0));        
    vector<vector<int>> vis(n, vector<int>(m, 0)); 

    // debug(mat,src,target,rule);
    q.push({src[0], src[1]});
    dis[src[0]][src[1]] = 0;
    vis[src[0]][src[1]] = 1;

    while(!q.empty()) {
        int currR = q.front().first;
        int currC = q.front().second;
        q.pop();

        if(currR == target[0] && currC == target[1]) {
            cout << dis[currR][currC] << endl;
            return;
        }
    
        int nextR,nextC;     
        nextR = currR + rule[0];
        nextC = currC + rule[1];

        // debug(currR,currC);
        // debug(nextR,nextC);

        if(isValid(nextR, nextC, n, m, vis, mat)) {
            vis[nextR][nextC] = 1;
            dis[nextR][nextC] = dis[currR][currC] + 1;
            q.push({nextR, nextC});
        }

        nextR = currR - rule[0];
        nextC = currC - rule[1];

        // debug(currR,currC);
        // debug(nextR,nextC);

        if(isValid(nextR, nextC, n, m, vis, mat)) {
            vis[nextR][nextC] = 1;
            dis[nextR][nextC] = dis[currR][currC] + 1;
            q.push({nextR, nextC});
        }

        nextR = currR + rule[1];
        nextC = currC - rule[0];

        // debug(currR,currC);
        // debug(nextR,nextC);

        if(isValid(nextR, nextC, n, m, vis, mat)) {
            vis[nextR][nextC] = 1;
            dis[nextR][nextC] = dis[currR][currC] + 1;
            q.push({nextR, nextC});
        }

        nextR = currR - rule[1];
        nextC = currC + rule[0];

        // debug(currR,currC);
        // debug(nextR,nextC);

        if(isValid(nextR, nextC, n, m, vis, mat)) {
            vis[nextR][nextC] = 1;
            dis[nextR][nextC] = dis[currR][currC] + 1;
            q.push({nextR, nextC});
        }
        
    }

    cout << 1e9 << endl;
}

int main(){
    fastio
    solve();
}
