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

//minimum weight to get value v
ll f(ll index,ll value_left,vector<ll> &weights,vector<ll> &values,vector<vector<ll>> &dp)
{
    if(value_left==0) return 0;
    if(index< 0 ) return 1e12;

    if(dp[index][value_left] !=-1 ) return dp[index][value_left];

    //take current
    ll take=1e12;
    if(value_left>=values[index])
    {
        take= weights[index] + f(index-1,value_left-values[index],weights,values,dp);
    }

    //not take
    ll notTake= f(index-1,value_left,weights,values,dp);

    return dp[index][value_left]=min(take,notTake);
}
 
 
void solve(){
   ll n,w;
   cin>>n>>w;

   vector<ll> weights(n),values(n);
   for(int i=0;i<n;i++)
    cin>>weights[i]>>values[i];

     ll maxValue = 0;
    for (int i = 0; i < n; ++i) {
        maxValue += values[i];
    }

    
    vector<vector<ll>> dp(n,vector<ll>(maxValue+1,-1));



   
    for(int i=maxValue;i>=0;i--)
    {
        if(f(n-1,i,weights,values,dp)<=w ){
            cout<<i<<endl;
            return;
        }
    }
    

}
 
 
int main(){
    fastio;
    
    solve();
    
}