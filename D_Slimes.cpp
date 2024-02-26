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
#define      MAX        1000000007
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

//just greater element to right , upper Bound
int searchToRight(ll num,vector<ll> &a,vector<ll> &distinctCnt,int i)
{
    ll n=a.size();

    ll ans=-1;
    ll l=0,r=n-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;

        if(a[mid]>num && distinctCnt[mid]-distinctCnt[i+1]+1>=2)
        { 
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    return ans;
} 

//greater element to left 
int searchToLeft(ll num,vector<ll> &a,vector<ll> &distinctCnt,int i)
{
    ll n=a.size();
    ll ans=-1;
    ll l=0,r=n-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(a[mid]>num &&  distinctCnt[i-1]-distinctCnt[mid]>0)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    return ans;
}
 
void solve(){
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(auto &x:a) {
        cin>>x;
    }

   
    vector<ll> pre(n),suff(n),distinctCnt(n);
    unordered_set<ll> unique;
    unique.insert(a[0]);
    distinctCnt[0]=1;
    pre[0]=a[0];
    for(ll i=1;i<n;i++)
    {
        
            pre[i]=pre[i-1]+a[i];
            unique.insert(a[i]);
            distinctCnt[i]=unique.size();
    
    }
    suff[n-1]=a[n-1];
    for(ll i=n-2;i>=0;i--)
    {
       
            suff[i]=suff[i+1]+a[i];
       
    }

    // debug(distinctCnt);
    vector<ll> ans(n);
    for(int i=0;i<n;i++)
    {   
       
        ll l=searchToLeft(suff[i]+a[i],suff,distinctCnt,i),r=searchToRight(pre[i]+a[i],pre,distinctCnt,i);

        // debug(i,l,r);
        if(l==-1 && r==-1)
        {
            ans[i]=-1;
        }
        else if(l==-1)
        {
            ans[i]=abs(r-i);
        }
        else if(r==-1)
        {
            ans[i]=abs(l-i);
        }
        else
            ans[i]=min(abs(l-i),abs(r-i));

        // ans[i]=searchToRight(pre[i]+a[i],pre);

        if(i-1>=0 && a[i]<a[i-1]) ans[i]=1;
        if(i+1<n && a[i]<a[i+1]) ans[i]=1;
    }

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