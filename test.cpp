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


int f(int wordIndex, int remLen, vector<string> &words, int m, int n)
{
    
    if (wordIndex == words.size())
        return (remLen+1) * (remLen+1) * (remLen+1);

    // go to new line and Add word
    int opt1 = (remLen+1) * (remLen+1) * (remLen+1) + f(wordIndex +1, m-words[wordIndex].size()-1, words, m, n);

    // put word in the same line
    int opt2 = 1e9;
    if (remLen >= words[wordIndex].size())
        opt2 = f(wordIndex+1,  remLen - words[wordIndex].size() - 1, words, m, n);

    // debug(wordIndex, remLen, opt1, opt2);
    return min(opt1, opt2);
}

int wordWrap(vector<string> words, int m, int n)
{
    return f(0, m, words, m, n);
}
 
 
void solve(){
    ll n,m;
    cin>>n>>m;

    vector<string> words(n);
    for(auto &x:words) cin>>x;

    cout<<wordWrap(words,m,n)<<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}