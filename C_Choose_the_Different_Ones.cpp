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

 
 
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    bool ok=true;

    ll cntA=0,cntB=0,cntCommon=0;
    for(int i=1;i<=k;i++)
    {
        if(binary_search(a.begin(),a.end(),i) && binary_search(b.begin(),b.end(),i))
        {
            cntCommon++;
        }
        else if(binary_search(a.begin(),a.end(),i))
            cntA++;
        else if(binary_search(b.begin(),b.end(),i))
            cntB++;
        else        
        {
            ok=false;
            break;
        } 
    }

    if(!ok)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(cntA<=k/2 && cntB<=k/2 && cntA+cntB+cntCommon==k)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
} 
 
int main(){
    fastio
    w(t){
        solve();
    }
}