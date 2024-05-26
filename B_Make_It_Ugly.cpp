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
    vector<ll> a(n);
    for(auto &x:a) cin>>x;
    
    ll maxFreqNo,maxFreq=0;
    map<ll,ll> mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
        if(mp[a[i]]>maxFreq)
        {
            maxFreq=mp[a[i]];
            maxFreqNo=a[i];
        }
    }

    vector<ll> other;
    other.push_back(-1);
    for(int i=0;i<n;i++)
    {
        if(a[i]!=maxFreqNo)
        {
            other.push_back(i);
        }
    }

    other.push_back(n);

    if(other.size()==2)
    {
        cout<<-1<<endl;
        return;
    }

   
    ll ans=INT_MAX;
    for(int i=1;i<other.size();i++)
    {
        ans=min(ans,other[i]-other[i-1]-1);
    }

    cout<<ans<<endl;
        


}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}