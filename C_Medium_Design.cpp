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
    ll q,n;
    cin>>q>>n;

    vector<pair<ll,ll>> vpr(q);
    for(ll i=0;i<q;i++)
        cin>>vpr[i].ff>>vpr[i].ss;

    sort(vpr.begin(),vpr.end());

    ll ans=0;

    //ignorinng left at 1;
    ll currOpen=0;
    set<ll> closed;
    map<ll,ll> cntClosed;

    
    for(ll i=0;i<q;i++)
    {
        if(vpr[i].ff==1) continue;

        while(closed.size() && vpr[i].ff>= *closed.begin())
        {
            currOpen-=cntClosed[*closed.begin()];
            closed.erase(closed.begin());
        }

        currOpen++;
        cntClosed[vpr[i].ss+1]++;
        closed.insert(vpr[i].ss+1);

        ans=max(ans,currOpen);
    }   


    //ignorinng right at n;
    sort(vpr.begin(),vpr.end(),[&](auto a,auto b){
        if(a.ss!=b.ss) return a.ss<b.ss;
        else return a.ff<b.ff;
    });

    currOpen=0;
    closed.clear();
    cntClosed.clear();

    
    for(ll i=q-1;i>=0;i--)
    {
        if(vpr[i].ss==n) continue;

        while(closed.size() && vpr[i].ss<= *closed.rbegin())
        {
            currOpen-=cntClosed[*closed.rbegin()];
            closed.erase(--closed.end());
        }

        currOpen++;
        cntClosed[vpr[i].ff-1]++;
        closed.insert(vpr[i].ff-1);

        ans=max(ans,currOpen);
    }    

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}