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


class Solution {
private:
    int f(int i,int lastIndex,int k,vector<int> &nums)
    {
        if(i<0) return 0;
        
        if(lastIndex==-1 || lastIndex-i<k)
        {
            int take=nums[i]+f(i-1,i,k,nums);
            int notTake=f(i-1,lastIndex,k,nums);
            
            return max(take,notTake);
        }
        else
        {
            int take=nums[i]+f(i-1,i,k,nums);
            
            return take;
        }
    }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();

        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
            maxi=max(maxi,nums[i]);

        int ans=f(n-1,-1,k,nums);

        if(ans==0)
            return maxi;

        return ans;    
        
    }
};
 
 
void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> nums(n);
    for(auto &x:nums) cin>>x;

    Solution obj;
    cout<<obj.constrainedSubsetSum(nums,k)<<endl;

}
 
 
int main(){
    fastio
    
        solve();
    
}