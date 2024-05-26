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

    vector<vector<char>> a(n,vector<char>(m));
    for(ll i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    //for white
    bool x1=false,x2=false,y1=false ,y2=false;
    for(ll i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='W')
            {
                if(i==0) x1=true;            
                if(i==n-1) x2=true;
                if(j==0) y1=true;
                if(j==m-1) y2=true;
        
            }
        }
    }

    if(x1 && x2 && y1 && y2)
    {
        cout<<"YES"<<endl;
        return;
    }


    //for black
     x1=false,x2=false,y1=false ,y2=false;
    for(ll i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='B')
            {
                if(i==0) x1=true;            
                if(i==n-1) x2=true;
                if(j==0) y1=true;
                if(j==m-1) y2=true;
        
            }
        }
    }

    if(x1 && x2 && y1 && y2)
    {
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;


    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}