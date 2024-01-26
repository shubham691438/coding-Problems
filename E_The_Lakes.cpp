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

int visited[1007][1007];
int cnt=0;

bool isvalid(int r,int c,vector<vector<int>>& grid){
    
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size())
        return false;
    if(visited[r][c]==1 || grid[r][c]==0)
        return false;
    return true;
}

void dfs(int r,int c,vector<vector<int>>& grid){
    visited[r][c]=1;
    cnt+=grid[r][c]; //count all the connected nodes depth
    if(isvalid(r-1,c,grid))
        dfs(r-1,c,grid);
    if(isvalid(r,c+1,grid))
        dfs(r,c+1,grid);
    if(isvalid(r+1,c,grid))
        dfs(r+1,c,grid);
    if(isvalid(r,c-1,grid))
        dfs(r,c-1,grid);
        
        
}


int maxVolumeOfLake(vector<vector<int>>& grid) {
    
    int rows=grid.size();
    int cols=grid[0].size();
    memset(visited,0,sizeof(visited));
    

int maxi=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(visited[i][j]==0 && grid[i][j]!=0){
                cnt=0;
                dfs(i,j,grid);
                maxi=max(cnt,maxi);   //max of all the connected nodes
                
            }
        }
    }
    
    return maxi;
    
}
 
 
void solve(){

    ll n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        // construct a vector of int
        vector<int> v;
        for (int j = 0; j < m; j++) {
            ll depth;
            cin>>depth;
            v.push_back(depth);
        }
 
        // push back above one-dimensional vector
        grid.push_back(v);
    }

    cout<<maxVolumeOfLake(grid)<<endl;;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}