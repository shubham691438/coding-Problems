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
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    vector<ll> firstElementToRight(n);
    
    firstElementToRight[n-1]=n;

    for(int i=n-2;i>=0;i--)
    {
        if(a[i]==a[i+1])
        {
            firstElementToRight[i]=firstElementToRight[i+1];
           
        }
        else 
        {
            firstElementToRight[i]=i+1;
        }
    }

    // debug(firstElementToRight);

    ll q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--,r--;

        if(a[l]!=a[r])
        {
            cout<<l+1<<" "<<r+1<<endl;
        }
        else
        {
            l=firstElementToRight[l];
            if(l<r)
            {
                cout<<l+1<<" "<<r+1<<endl;
            }
            else
            {
                cout<<-1<<" "<<-1<<endl;
            }
        }
    }

    cout<<endl;



}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}