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

 //implementation of is_increasing function
 bool is_increasing(vector<ll>::iterator begin, vector<ll>::iterator end){
    if(begin==end) return true;
    auto next = begin;
    for(auto it = begin+1;it!=end;it++){
        if(*it<*next){
            return false;
        }
        next = it;
    }
    return true;
 }    
 
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    if(n==3){
        cout<<"YES\n";
        return;
    }

    vector<ll> gcd_arr;
    for(int i=0;i<n-1;i++){
        gcd_arr.push_back(__gcd(a[i],a[i+1]));
    }

    if(is_increasing(gcd_arr.begin(),gcd_arr.end())){
        cout<<"YES\n";
        return;
    }

    ll firstDecreasingIndex = -1;

    for(int i=0;i<gcd_arr.size()-1;i++){
        if(gcd_arr[i]>gcd_arr[i+1]){
            firstDecreasingIndex = i+1;
            break;
        }
    }

    vector<ll> p;
    if(firstDecreasingIndex-2>=0) p.push_back(firstDecreasingIndex-2);
    if(firstDecreasingIndex-1>=0) p.push_back(firstDecreasingIndex-1);
    if(firstDecreasingIndex>=0) p.push_back(firstDecreasingIndex);
    if(firstDecreasingIndex+1<n) p.push_back(firstDecreasingIndex+1);
    if(firstDecreasingIndex+2<n) p.push_back(firstDecreasingIndex+2);
    if(firstDecreasingIndex+3<n) p.push_back(firstDecreasingIndex+3);
    


    // debug(p);
    for(auto x:p){
        vector<ll> temp = a;
        temp.erase(temp.begin()+x);
        vector<ll> temp_gcd;
        for(int i=0;i<temp.size()-1;i++){
            temp_gcd.push_back(__gcd(temp[i],temp[i+1]));
        }
        if(is_increasing(temp_gcd.begin(),temp_gcd.end())){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
    
}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}