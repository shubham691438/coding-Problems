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
 ll n,x;
 cin>>n>>x;

 vector<ll> a(n);
 for(int i=0;i<n;i++)
    cin>>a[i];

 ll maxi=a[0];
 for(int i=1;i<n;i++)
    maxi=max((a[i]-a[i-1]),maxi );

     maxi=max(2*(x-a[n-1]),maxi);

    cout<<maxi<<endl;   
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}