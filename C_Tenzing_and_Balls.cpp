//    https://www.youtube.com/watch?v=TDD1JVXkHLg
    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    int solve(int ind,int cond,vector<vector<int>>&res,vector<int>&v, vector<vector<int>>&dp){
        if(ind==v.size()){
            return 0;
        }
        if(dp[ind][cond]!=-1){
            return dp[ind][cond];
        }
        
        int notTake,take=INT_MAX;
        
        //if not taking the next index 
        notTake=cond+solve(ind+1,1,res,v,dp);

        int id=upper_bound(res[v[ind]].begin(),res[v[ind]].end(),ind)-res[v[ind]].begin();

        //if taking the next index if it exists
        if(id!=res[v[ind]].size()){
            take=solve(res[v[ind]][id],0,res,v,dp);
        }
            return dp[ind][cond]=min(take,notTake);
       
       
    }
    signed main(){
        int t;cin>>t;
        while ( t--)
        {   
          int n;cin>>n;
          vector<int>v(n);
          vector<vector<int>>res(n+1);
          for ( int i = 0; i <  n; i++)
          {
             cin>>v[i];
             res[v[i]].push_back(i);
          }

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
          int ans=solve(0,1,res,v,dp);
          cout<<n-ans<<endl;



          
        }
    }
    