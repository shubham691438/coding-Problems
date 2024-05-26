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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(2*n);
    for(auto &x:a) cin>>x;

    vector<ll> l(n),r(n);
    for(int i=0;i<n;i++)
    {
        l[i]=a[i];
        r[i]=a[n+i];
    }

    sort(all(l));
    sort(all(r));

    vector<ll> doubleL;
    vector<ll> singleL;
    ll i=0;
    while(i<n)
    {
        if(i+1<n && l[i]==l[i+1])
        {
            doubleL.pb(l[i]);
            doubleL.pb(l[i]);
            i+=2;
        }
        else
        {
            singleL.pb(l[i]);
            i++;
        }
    }

    // debug(doubleL,singleL);
    vector<ll> doubleR;
    vector<ll> singleR;
    i=0;
    while(i<n)
    {
        if(i+1<n && r[i]==r[i+1])
        {
            doubleR.pb(r[i]);
            doubleR.pb(r[i]);
            i+=2;
        }
        else
        {
            singleR.pb(r[i]);
            i++;
        }
    }

    for(int i=0;i<2*k;i++)
    {
        if(i<doubleL.size())
        {
            cout<<doubleL[i]<<" ";
        }
        else
        {
            cout<<singleL[i-doubleL.size()]<<" ";
        }
    }

    cout<<endl;

    for(int i=0;i<2*k;i++)
    {
        if(i<doubleR.size())
        {
            cout<<doubleR[i]<<" ";
        }
        else
        {
            cout<<singleL[i-doubleL.size()]<<" ";
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