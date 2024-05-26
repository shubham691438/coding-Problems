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

bool ok(ll k, vector<ll> &a)
{
    ll n = a.size();
    vector<ll> bit(20, 0);
    
    // Initialize bit array with the first k elements
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            bit[j] += (a[i] & (1 << j)) ? 1 : 0;
        }
    }


    // Slide the window of size k and check each subarray
    for(int i = 1; i <= n - k; i++)
    {
        vector<ll> currBit=bit;

        // Remove the contribution of the element that is sliding out of the window
        for(int j = 0; j < 20; j++)
        {
            currBit[j] -= (a[i - 1] & (1 << j)) ? 1 : 0;
        }

        // Add the contribution of the new element that is entering the window
        for(int j = 0; j < 20; j++)
        {
            currBit[j] += (a[i + k - 1] & (1 << j)) ? 1 : 0;
        }

          //check with original bit
       for(int j=0;j<20;j++)
       {    
            if(currBit[j]<0) return false;
            
            if( (bit[j]==0 && currBit[j]==0) || (bit[j]>0 && currBit[j]>0)) continue;

            return false;
       }

       bit=currBit;

    }

    return true;
}

 
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;
    
    ll ans=n;
    ll l=1, r=n;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(ok(mid,a))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l= mid+1;
        }
    }

    cout<<ans<<endl;

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}