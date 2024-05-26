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
/*-----------------------------------------------------------------------------------*/


bool isPossible(ll burger_cnt, vector<ll> &available, vector<ll> &p, vector<ll> &ratio,ll money)
{
    ll totalCost=0;

    //bread required for burger_cnt= burger_cnt*ratio[0]
    if( (burger_cnt*ratio[0] - available[0]) > 0LL) totalCost+= (burger_cnt*ratio[0] - available[0])*p[0];
    if( (burger_cnt*ratio[1] - available[1]) > 0LL) totalCost+= (burger_cnt*ratio[1] - available[1])*p[1];
    if( (burger_cnt*ratio[2] - available[2]) > 0LL) totalCost+= (burger_cnt*ratio[2] - available[2])*p[2];

    if(totalCost<=money) return true;
    return false;

} 
 
void solve(){
    string burger;
    cin>>burger;

    vector<ll> available(3);
    cin>>available[0]>>available[1]>>available[2];

    vector<ll> p(3);
    cin>>p[0]>>p[1]>>p[2];

    ll money;
    cin>>money;

    vector<ll> ratio(3);
    for(ll i=0;i<burger.size();i++)
    {
        if(burger[i]=='B') ratio[0]++;
        else if(burger[i]=='S') ratio[1]++;
        else ratio[2]++;
    }

    ll ans=0;
    ll l=0,r=1e15+7;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;

        if(isPossible(mid,available,p,ratio,money))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio;
    
        solve();
    
}