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

 
 
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll cnt1=0;
    int i=0,j=m-1;
    int k=0,l=n-1;
    while(k<=l)
    {
        ll num;
        ll left=0,right=0;

        num=a[k];
        if(abs(b[i]-num) > abs(b[j]-num))
        {
            left+=abs(b[i]-num);

        }
        else
        {
            left+=abs(b[j]-num);
        }

        num=a[l];
        if(abs(b[i]-num) > abs(b[j]-num))
        {
            right+=abs(b[i]-num);
        }
        else
        {
            right+=abs(b[j]-num);
        }

        if(left>right)
        {
            
            num=a[k];
            if(abs(b[i]-num) > abs(b[j]-num))
            {
                cnt1+=abs(b[i]-num);
                i++;

            }
            else
            {
                cnt1+=abs(b[j]-num);
                j--;
            }
            k++;

        }
        else
        {
            num=a[l];
            if(abs(b[i]-num) > abs(b[j]-num))
            {
                cnt1+=abs(b[i]-num);
                i++;

            }
            else
            {
                cnt1+=abs(b[j]-num);
                j--;
            }
            l--;
        }
    }

    //  sort(a.begin(),a.end(),greater<int>());

    ll cnt2=0;
    // i=0,j=m-1;
    // for(int k=0;k<n;k++)
    // {
    //     ll num=a[k];
    //     if(abs(b[i]-num) > abs(b[j]-num))
    //     {
    //         cnt2+=abs(b[i]-num);
    //         i++;
    //     }
    //     else
    //     {
    //         cnt2+=abs(b[j]-num);
    //         j--;
    //     }
    // }

    cout<<max(cnt1,cnt2)<<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}