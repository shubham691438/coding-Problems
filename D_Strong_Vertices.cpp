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
    
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int mx=INT_MIN;
    for(int i=1;i<=n;i++)mx=max(mx,a[i]-b[i]);
    int c=0;
    for(int i=1;i<=n;i++)c+=(a[i]-b[i]==mx);
    cout<<c<<endl;
    for(int i=1;i<=n;i++)if(a[i]-b[i]==mx)cout<<i<<' ';
    cout<<endl;
    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}