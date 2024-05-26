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

 bool isSingleDigit(ll n)
 {
    if(n/10==0) return true;
    return false;
 }
 
void solve() {
    string str;
    cin >> str;

    ll hr = stoi(str.substr(0, 2));
    ll min = stoi(str.substr(3, 2));

    if (hr < 12) {
        cout << (hr==0?"12":(isSingleDigit(hr) ? "0" + to_string(hr) : to_string(hr))) << ':'
             << (isSingleDigit(min) ? "0" + to_string(min) : to_string(min)) << " AM" << endl;
    } else {
        cout << (hr==12? to_string(hr) : (isSingleDigit(hr - 12) ? "0" + to_string(hr - 12) : to_string(hr - 12))) << ':'
             << (isSingleDigit(min) ? "0" + to_string(min) : to_string(min)) << " PM" << endl;
    }
}


 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}