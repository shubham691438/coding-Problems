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

//O(1)
ll nc2(ll n)
{
    if(n<2) return 0;

    return n*(n-1)/2;
}

//O(1)
ll getPairCnt(ll c,ll k)
{
    if(k>c)
        k=c;

    if(c%k==0)
    {
        ll y=c/k;
        return k*(k-1)*y*y/2;
    }

    else
    {
        ll y=c/k;
        ll y1=ceil((double)c/k);

        return nc2(c%k)*y1*y1+nc2(k-c%k)*y*y+ (c%k) * y1 * (k-c%k) * y;
    }
        
} 
 
void solve(){
    ll n,b,x;
    cin>>n>>b>>x;

    ll mx=0;
    vector<ll> a(n);
    for(auto &x:a)
    {
        cin>>x;
        mx=max(x,mx);
    }

    ll ans=0;
    for(int sqd=1;sqd<=mx;sqd++)
    {
        ll currStrength=0;
        for(int i=0;i<n;i++)
        {
            // debug(sqd,i,getPairCnt(a[i],sqd));
            currStrength+=getPairCnt(a[i],sqd)*b;
        }
        currStrength-=(sqd-1)*x;
        // debug(sqd,currStrength);
        ans=max(ans,currStrength);
    }

    cout<<ans<<endl;

}
 
 
int main(){
    
    fastio
    w(t){
        solve();
    }
}