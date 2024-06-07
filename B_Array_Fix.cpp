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

 //imlement is_sorted function
bool is_sorted(vector<ll> &a){
    for(int i=1;i<a.size();i++){
        if(a[i]<a[i-1]) return false;
    }
    return true;
}    
 
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;
    
    vector<ll> b;
    for(ll i=0;i<n;i++){
        if(i==n-1 || a[i]/10==0)
        {
            b.push_back(a[i]);
        }
        else if(a[i]<=a[i+1]){
           
                vector<ll> temp;
                ll num=a[i];
                while(num>0){
                    temp.push_back(num%10);
                    num/=10;
                }
                reverse(temp.begin(),temp.end());

                if(is_sorted(temp) && (b.empty() || temp[0]>=b.back()) && temp[temp.size()-1] <=a[i+1] ){
                    for(int i=0;i<temp.size();i++){
                        b.push_back(temp[i]);
                    }
                }
                else{
                    b.push_back(a[i]);
                }
                
        }
        else if( a[i]>a[i+1] ){
            vector<ll> temp;
            ll num=a[i];
            while(num>0){
                temp.push_back(num%10);
                num/=10;
            }
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                b.push_back(temp[i]);
            }
        }
    }

    // debug(b);

    if(!is_sorted(b))
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}