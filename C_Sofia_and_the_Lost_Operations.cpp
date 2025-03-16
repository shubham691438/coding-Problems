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
    vector<ll> a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    ll m;
    cin>>m;
    vector<ll> d(m);
    for(auto &x:d) cin>>x;

    map<ll,ll> change;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            change[b[i]]++;
        }
    }

    

    map<ll,ll> dMap;
    for(int i=0;i<m;i++){
        dMap[d[i]]++;
    }

    for(auto ele:change){
        if(dMap[ele.ff]<ele.ss){
            cout<<"NO"<<endl;
            return;
        }
    }


    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            change[b[i]]++;
        }
    }

    bool ok = false;
    for(int i=m-1;i>=0;i--){

        if(change.find(d[i])!=change.end()){
            ok = true;
        }
        else{
            if(!ok){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;

    


    


}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}