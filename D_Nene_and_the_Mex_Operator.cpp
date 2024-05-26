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

 vector<pair<ll,ll>> moves(ll i,ll j)
 {
    vector<pair<ll,ll>> res;
    if(i==j)
    {
        res.push_back({i,j});
        return res;
    }

    ll r=j;
    while(i+1<=r)
    {
        auto mvs=moves(i+1,r);
        for(auto &x:mvs) res.push_back(x);
        r--;

        if(i+1<=r) res.push_back({i+1,r});

    }

    res.push_back({i,j});

    return res;
 }
 
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<ll> dp(n+1);
    vector<vector<pair<ll,ll>>> mv(n+1);

    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        mv[i]=mv[i-1];

        bool has_zero=false;
        for(int j=i;j>=1;j--)
        {   
           has_zero |= a[j] == 0;
            ll sum=dp[j-1]+ (i-j+1)*(i-j+1);

            if( sum > dp[i] )
            {
                dp[i]=sum;
                mv[i]=mv[j-1];

                if(has_zero)
                {
                    mv[i].push_back({j,i});
                    mv[i].push_back({j,i});
                }
                else
                {
                    mv[i].push_back({j,i});
                }

                vector<pair<ll,ll>> mvs=moves(j,i);
                for(auto &x:mvs) mv[i].push_back(x);

            }
        }
    }


    cout<<dp[n]<<" "<<mv[n].size()<<endl;
    for(auto pr:mv[n]) cout<<pr.first<<" "<<pr.second<<endl;
    
}
 
 
int main(){
    fastio;
    
        solve();
   
}