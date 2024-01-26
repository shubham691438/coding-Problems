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
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }  

    sort(a.begin(),a.end());

    int ans=0;
    for(int i=0;i<n/2;i++)
        ans+=a[n-i-1]-a[i];

    cout<<ans<<endl;    

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}