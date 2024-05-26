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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;
    
   //trying to put max at odd positions
    set<pair<ll,ll>> st;
    for(int i=1;i<n-1;i+=2)
    {
        st.insert({a[i],i});
    }

    vector<ll> ans(n);
    ll curr=n;
    for(auto ele:st)
    {
        ll index=ele.second;
        ans[index]=curr;
        curr--;
    }   

    set<pair<ll,ll>,greater<pair<ll,ll>>> st2;
    st2.insert({a[0],0});
    st2.insert({a[n-1],n-1});
    for(int i=2;i<n-1;i+=2)
    {
        st2.insert({a[i],i});
    }

    curr=1;
    for(auto ele:st2)
    {
        ll index=ele.second;
        ans[index]=curr;
        curr++;
    }

   

    bool ok=true;

    ll cnt=0;
    for(int i=1;i<n-1;i++)
    {
        if(a[i]+ans[i]>a[i-1]+ans[i-1] && a[i]+ans[i]>a[i+1] + ans[i+1])
            cnt++;
    }


    
    if(cnt==n/2-1)
    {
       
         for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

        cout<<endl;  
        return;  
    }

    //trying to put max at even positions
    st.clear();
    for(int i=2;i<n-1;i+=2)
    {
        st.insert({a[i],i});
    }


    curr=n;
    for(auto ele:st)
    {
        ll index=ele.second;
        ans[index]=curr;
        curr--;
    }   

     st2.clear();
    st2.insert({a[0],0});
    st2.insert({a[n-1],n-1});
    for(int i=1;i<n-1;i+=2)
    {
        st2.insert({a[i],i});
    }

    curr=1;
    for(auto ele:st2)
    {
        ll index=ele.second;
        ans[index]=curr;
        curr++;
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    cout<<endl;    





}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}