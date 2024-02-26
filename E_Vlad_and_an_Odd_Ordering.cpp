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

//SIEVE TO CHECK PRIMES
vector<int> prime(MAX+1);
void sieve_prime()
{     
      for(ll i=0;i<=MAX;i++)
            prime[i]=1;

      prime[0]=prime[1]=0;

      for(ll i=2;i*i<=MAX;i++)
      {
            if(prime[i])
            {
                  for(ll j=i*i;j<=MAX;j+=i)
                        prime[j]=0;
            }
      }
}
ll ans(ll n,ll k)
{

    ll firstHalf=ceil((double)n/2);
    if( k<=  firstHalf)
    {
        //return kth odd number
        return 1+(k-1)*2;

    }
    
    return 2* ans(n-firstHalf,k-firstHalf);
} 
 
void solve(){
    ll n,k;
    cin>>n>>k;

    cout<<ans(n,k)<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}