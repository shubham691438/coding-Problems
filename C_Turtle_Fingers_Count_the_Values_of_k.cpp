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

 bool isPower(int num, int base) {
    // If num is less than 1, it cannot be a power of any number
    if (num < 1) {
        return false;
    }
    
    // Calculate the logarithm of num with the given base
    double logarithm = (double)log(num) / log(base);

    // If the logarithm is an integer, then num is a power of base
    return floor(logarithm) == logarithm;
}

bool isPossible(ll f,vector<ll> &a)
{
    
    for(auto num:a)
    {
        if(f==num)
            return true;
    }
    return false;
} 
void solve(){
    ll a,b,l;
    cin>>a>>b>>l;

    //get all the factors of l
    vector<ll> factors;
    for(ll f=1;f*f<=l;f++)
    {
        if(l%f==0)
        {   
            if(f==l/f)
                factors.push_back(f);
            else
            {
                factors.push_back(f);
                factors.push_back(l/f);
            }    
        }
    }

    sort(factors.begin(),factors.end());

    //get powers of a
    vector<ll> powerA;
    for(ll i=1;i<=l;i=i*a)
    {
        powerA.push_back(i);
    }

    //get powers of b
    vector<ll> powerB;
    for(ll i=1;i<=l;i=i*b)
    {
        powerB.push_back(i);
    }

    //get all the possible factors;
    unordered_set<ll> st;
    for(auto f:factors)
    {
        bool ok=false;
        ll fac=f;
        while(fac)
        {
            if(isPossible(fac,powerA) || isPossible(fac,powerB))
                ok=true;

            if(fac%(a*b)==0)
                fac=fac/(a*b);
            else
            {
                break;
            }    
        }

        if(ok) st.insert(f);
        
    }

    // debug(st);
    // debug(powerA);
    // debug(powerB);
    cout<<st.size()<<endl;
    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}