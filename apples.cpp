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
bool possible(int k,int x,vector<int> &a)
{
    int n=a.size();
    int sum=0;
    int prevSum=0;

    // debug(k);
    for(int i=0;i<n;i++)
    {
        prevSum+=a[i];
        int currSum=prevSum;
        int cnt=2;
        for(int j=i+1;j<n;j++)
        {
            // debug(cnt);
            if(cnt<=k)
            {   
                // debug(cnt,a[j]);
                currSum+=cnt*a[j];
                cnt++;
            }
            else{
                cnt=1;
            }
        }

    //    debug(currSum);

        sum=max(currSum,sum);
    }

    if(sum>=x) return true;
    else return false;
}
int solve(int n,int x, vector<int> &a) 
{
    // sort(a.begin(),a.end());

    
    int l=1,r=n;
    ll ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;

        if(possible(mid,x,a))
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
 
void solve1(){
    ll n,x;
    cin>>n>>x;

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    cout<<solve(n,x,a)<<endl;
}
 
 
int main(){
    fastio
    // w(t){
        solve1();
    // }
}