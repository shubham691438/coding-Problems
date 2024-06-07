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
    ll n,k,a,b;
    cin>>n>>k>>a>>b;

    a--;
    b--;

    vector<pair<ll,ll>> cities(n);
    for(ll i=0;i<n;i++)
    {
        cin>>cities[i].ff>>cities[i].ss;
    }


    pair<ll,ll> closestA={a,1e15};
    pair<ll,ll> closestB={b,1e15};

    vector<pair<ll,ll>>  disA(n);
    vector<pair<ll,ll>>  disB(n);
    for(int i=0;i<k;i++)
    {
        disA[i]={abs(cities[i].ff-cities[a].ff)+abs(cities[i].ss-cities[a].ss),i};
        if(disA[i].ff<closestA.ss)
        {
            closestA={i,disA[i].ff};
        }
        
    }

    for(int i=0;i<k;i++)
    {
        disB[i]={abs(cities[i].ff-cities[b].ff)+abs(cities[i].ss-cities[b].ss),i};
        if(disB[i].ff<closestB.ss)
        {
            closestB={i,disB[i].ff};
        }
    }

    // debug(closestA,closestB);
    cout<<min( closestA.ss+closestB.ss , abs(cities[a].ff-cities[b].ff)+abs(cities[a].ss-cities[b].ss) )<<endl;



    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}