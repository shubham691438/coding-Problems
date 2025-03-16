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

 
 
void solve(){
    ll n,u;
    cin>>n>>u;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    vector<ll> prefixSum=a;
    for(int i=1;i<n;i++)
        prefixSum[i]=prefixSum[i-1]+prefixSum[i];

    vector<ll> v(n);
    for(int i=0;i<n;i++)  
    {
        v[i]= (i-1>=0 ? prefixSum[i-1]:0) + a[i] + u;
    }  

    vector<ll> ans(n);

    a[0]+=u;
    pair<ll,ll> maxi={0,0};
    for(int i=0;i<n;i++)
    {
        if(a[i]>maxi.first)
        {
            maxi.first=a[i];
            maxi.second=i;
        }
    }
    a[0]-=u;

    ans[maxi.second]=0;

    vector<ll> suffix_max=a;
    for(int i=n-2;i>=0;i--)
    {
        suffix_max[i]=max(suffix_max[i],suffix_max[i+1]);
    }

    // if(maxi.second-1>=0 && maxi.first<= v[maxi.second-1]) ans[maxi.second]= maxi.second;

    for(int i=0;i<n;i++)
    {
        if(i==maxi.second) continue;

        if(i+1<n && suffix_max[i+1]>v[i]) ans[i]=i+1;
        else ans[i]=i;
    }


    for(auto &x:ans) cout<<x<<" ";
    cout<<endl;

    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}