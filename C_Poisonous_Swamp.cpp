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

    vector<vector<int>> a(2,vector<int>(n));
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch;
            cin>>ch;

            if(ch=='*')
                a[i][j]=1;
            else
                a[i][j]=0;    
        }
    }

    

    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[0][i]==1)
        {
            cnt++;
        }
        else if(cnt){
            ans+=cnt-1;
            cnt=0;
        }
    }

    if(cnt)
    {
        ans+=cnt-1;
    }

    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[1][i]==1)
        {
            cnt++;
        }
        else if(cnt){
            ans+=cnt-1;
            cnt=0;
        }
    }

    if(cnt)
    {
        ans+=cnt-1;
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}