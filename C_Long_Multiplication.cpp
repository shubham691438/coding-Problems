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

 
 
void solve(){
    string s1,s2;
    cin>>s1;
    cin>>s2;

    ll n =s1.size();
    vector<int> num1(n),num2(n);
    for(int i=0;i<n;i++)
    {
        num1[i]=s1[i]-'0';
        num2[i]=s2[i]-'0';
    }

    vector<int> ans1(n),ans2(n);
    bool firstUnequal=true;
    for(int i=0;i<n;i++)
    {
        if(num1[i]==num2[i])
        {
            ans1[i]=num1[i];
            ans2[i]=num2[i];
        }
        else if(firstUnequal)
        {
            firstUnequal=false;
            ans1[i]=max(num1[i],num2[i]);
            ans2[i]=min(num1[i],num2[i]);
        }
        else
        {
            firstUnequal=false;
            ans2[i]=max(num1[i],num2[i]);
            ans1[i]=min(num1[i],num2[i]);
        }
    }

    for(int i=0;i<n;i++)
        cout<<ans1[i];

    cout<<endl;

    for(int i=0;i<n;i++)
        cout<<ans2[i];

    cout<<endl;        
    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}