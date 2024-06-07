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

//write a function to convert a number to its binary form and return as array
vector<ll> getBinary(ll n){
    vector<ll> binary;
    while(n>0){
        binary.push_back(n%2);
        n/=2;
    }
    reverse(all(binary));
    return binary;
}
 
 
void solve(){
    ll n;
    cin>>n;
    

    vector<ll> res = getBinary(n);
    res.insert(res.begin(),0);
    
    ll carry=0;
    for(int i=res.size()-2;i>=1;i--)
    {   
        res[i]+=carry;
        carry=(res[i])/2;
        res[i]=(res[i])%2;
        

        if(res[i]!=0 && res[i+1]!=0)
        {
            res[i+1]=-1;
            res[i]=0;
            res[i-1]=res[i-1]+1;
        }
    }
    res[0]=carry+res[0];
    cout<<res.size()<<endl;

    reverse(res.begin(),res.end());
    for(auto &x:res) cout<<x<<" ";
    cout<<endl;

    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}