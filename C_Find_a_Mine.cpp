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
    ll n,m;
    cin>>n>>m;

    cout<<"? 1 1"<<endl;
    cout<<flush;

    ll d1;
    cin>>d1;

    if(d1==0)
    {
        cout<<"! "<<1<<" "<<1<<endl;
        cout.flush();
        return;
    }
    
    
    ll i1= min(1+d1,n);
    ll j1= 1+(d1-(i1-1));

    ll j2=min(1+d1,m);
    ll i2=1+(d1-(j2-1));

    // debug(i1,j1);
    // debug(i2,j2);


    cout<<"? "<<i1<<" "<<j1<<endl;
    cout<<flush;
    ll d2;
    cin>>d2;

    if(d2==0)
    {
        cout<<"! "<<i1<<" "<<j1<<endl;
        cout.flush();
        return;
    }

    cout<<"? "<<i2<<" "<<j2<<endl;
    cout<<flush;
    ll d3;
    cin>>d3;
    
    if(d3==0)
    {
        cout<<"! "<<i2<<" "<<j2<<endl;
        cout<<flush;
        return;
    }

    cout<<"? "<<i1-d2/2<<" "<<j1+d2/2<<endl;
    cout<<flush;
    ll d4;
    cin>>d4;

    if(d4==0)
    {
        cout<<"! "<<i1-d2/2<<" "<<j1+d2/2<<endl;
        cout<<flush;
        return ;
    }

    // cout<<"? "<<i2+d2/2<<" "<<j2-d2/2<<endl;
    // cout<<flush;
    // ll d5;
    // cin>>d5;

    
    
    cout<<"! "<<i2+d3/2<<" "<<j2-d3/2<<endl;
    cout<<flush;
        return ;
   

    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}