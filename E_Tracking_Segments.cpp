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

bool beautiful(int l,int r,vector<int> &preSum,int n)
{
    if( (preSum[r]-preSum[l-1]) > (r-l+1)/2 )
        return true;
    else 
        return false;    
}

bool isPossible(int no_of_changes,int n,int m,vector<pair<int,int>> &seg,vector<int> &queries)
{
    vector<int> a(n+1,0);
    for(int i=0;i<no_of_changes;i++)
    {
        a[queries[i]]=1;
    }

    vector<int>preSum(n+1,0);
    for(int i=1;i<=n;i++)
        preSum[i]+=preSum[i-1]+a[i];

   //check for each segment if any one of them is beautiful
   for(int i=0;i<m;i++)
   {
     if(beautiful(seg[i].ff,seg[i].ss,preSum,n)) return true;
   }

   return false;
}
 
 
void solve(){

    //TAKING INPUTS
    ll n,m;
    cin>>n>>m;

    vector<pair<int,int>> seg(m);
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        seg[i]={l,r};
    } 

    ll q;
    cin>>q;
    vector<int> queries(q);
    for(auto &x:queries) cin>>x;

    //BINARY SEARCH
    //if it is beautiful after applying y changes then it is also beautiful for y+1 changes and so on
    //hence binary search can be applied on it

    int l=0,r=q,mid,ans=-1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(isPossible(mid,n,m,seg,queries))
        {
            ans=mid;
            // cout<<"mid : "<<mid<<endl;
            r=mid-1;
        }
        else
        {
            l=mid+1;
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