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

vector<int> getDivisors(int n)
{
    vector<int> divisors;

    unordered_set<int> st;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
           st.insert(i);
           st.insert(n/i);
        }
    }

    for(auto ele:st)
        divisors.push_back(ele);
    return divisors;
}
 //GCD
 ll gcd(ll a,ll b)
 {
       if(b==0)
            return a;
       else
            return gcd(b,a%b);
 }
 
void solve(){
    ll n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> divisors=getDivisors(n);

    sort(divisors.begin(),divisors.end());

    int cnt=0;
    for(int i=0;i<divisors.size();i++)
    {
        int k=divisors[i];
        int GCD=0;
        for(int j=0;j+k<n;j++)
        {
            GCD=gcd(GCD,abs(a[j+k]-a[j]));
        }
        if(GCD!=1)
        {
            cnt++;
        }
    }

    cout<<cnt<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}