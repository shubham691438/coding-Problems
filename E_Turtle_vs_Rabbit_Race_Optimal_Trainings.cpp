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


ll bs(ll num,vector<ll> &a,ll l, ll r)
{
    ll ans=a.size()-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;

        if(a[mid]<=num)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    return ans;

} 
 
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    vector<ll> preSum(n+1);
    for(int i=1;i<=n;i++) preSum[i]=preSum[i-1]+a[i];

    // debug(preSum);
    ll q;
    cin>>q;
    while(q--)
    {
        ll l,u;
        cin>>l>>u;

        if(u<=a[l])
        {
            cout<<l<<" ";
            continue;
        }

        ll r=bs(preSum[l-1]+u,preSum,l,n);

        ll sum=preSum[r]-preSum[l-1];

        if(sum==u || r==n) 
        {
            // debug(l,r,sum);
            cout<<r<<" ";
            
        }
        else
        {
            ll sum2=preSum[r+1]-preSum[l-1];


            // debug(l,r,sum,sum2);
            if(sum2>=u+1 && sum2<= u+(u-sum))
                cout<<r+1<<" ";
            else
                cout<<r<<" ";

        }   

       
        

        
    }
    cout<<endl;

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}