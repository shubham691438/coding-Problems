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

 
 bool isKthBitSet(int n, int k)
{
    if (n & (1 << k))
        return true;
    else
        return false;
}
void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;


    map<ll,ll> mp;
    unordered_set<ll> st;
    for(ll i=0;i<n;i++)
        mp[a[i]]++;

        

    ll ans=n;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
       
        ll num= a[i] ^ ((1LL << 31) - 1LL);
        
        if(binary_search(a.begin(),a.end(),num) && st.count(num)==0 && st.count(a[i])==0 )
        {
            ans-= min(mp[num],mp[a[i]]);
            st.insert(a[i]);
            st.insert(num);
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