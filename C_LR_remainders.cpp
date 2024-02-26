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

// Function to calculate the greatest common divisor using the Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

// Function to find modular inverse of a modulo m
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);
    if (gcd != 1) {
        // Modular inverse doesn't exist
        return -1;
    }
    // Ensure the result is positive
    return (x % m + m) % m;
}

 
void solve(){
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    string str;
    cin>>str;

    ll last;
    ll l=0,r=n-1;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='L')
        {
            last=l;
            l++;
        }
        else
        {
            last=r;
            r--;
        }
    }

    vector<ll> ans;
    
    ll curr=a[last]%m;
    ans.push_back(curr);

    l=last,r=last;
    for(int i=n-2;i>=0;i--)
    {
        if(str[i]=='R')
        {
            r++;
            curr=(curr*a[r])%m;
            ans.push_back(curr);
        }
        else
        {
            l--;
            curr=(curr*a[l])%m;
            ans.push_back(curr);
        }
    }
    
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    cout<<endl;    


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}