#include<bits/stdc++.h>
using namespace std;
 
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
    ll n;
    cin>>n;
    vector<int> a(2*n);
    for(auto &x:a) cin>>x;

    sort(a.begin(),a.end());

    int ans=0;
    for(int i=1;i<n;i++)
        ans+=a[i]-a[i-1];

    for(int i=n+1;i<2*n;i++) 
        ans+=a[i]-a[i-1];

    cout<<ans<<endl;
    for(int i=0,j=2*n-1;i<n;i++,j--)
    {
        cout<<a[i]<<" "<<a[j]<<endl;
    }       

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}