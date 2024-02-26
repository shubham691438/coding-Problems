//https://www.youtube.com/watch?v=WKvn7vVdvHs

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
    ll n,m;
    cin>>n>>m;

    string str;
    cin>>str;

    vector<ll> nearestZeroToLeft(n),nearestOneToRight(n);
    ll nz=-1,no=n;

    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')
            nz=i;

        nearestZeroToLeft[i]=nz;
    }

    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='1')
            no=i;

        nearestOneToRight[i]=no;    
    }

    set<pair<ll,ll>> st;

    ll original=0;
    while(m--)
    {
        ll l,r;
        cin>>l>>r;
        l--,r--;

        ll firstChnage=nearestOneToRight[l];
        ll LastChange=nearestZeroToLeft[r];

        if(firstChnage<LastChange)
            st.insert({firstChnage,LastChange});

        else{
            original=1;
        }    

    }

    cout<<st.size()+original<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}