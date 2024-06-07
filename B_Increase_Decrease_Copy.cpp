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
    ll n;
    cin>>n;
    vector<ll> a(n),b(n+1);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(a[i]-b[i]);
    }

    ll nearest=b[n];
    ll diff=INT_MAX;

    ll found=false;
    for(int i=0;i<n;i++)
    {
        if(b[n]==min(a[i],b[i]) || b[n]==max(a[i],b[i]) )
        {
            found=true;
            break;
        }

        if(b[n]>min(a[i],b[i])  && b[n]<max(a[i],b[i]) )
        {
           found=true;
           break;
        }

        if(abs(b[n]-a[i])<diff)
        {
            diff=abs(b[n]-a[i]);
            nearest=a[i];
        }

        if(abs(b[n]-b[i])<diff)
        {
            diff=abs(b[n]-b[i]);
            nearest=b[i];
        }
    }

    // debug(nearest,diff,found,ans);
    if(found)
    {
        cout<<ans+1<<endl;
        return;
    }

    cout<<ans+diff+1<<endl;
    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}