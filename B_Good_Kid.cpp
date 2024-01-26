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

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    sort(a.begin(),a.end());

    a[0]=a[0]+1;
    ll prod=1;
    for(int i=0;i<n;i++)
    {
        prod=prod*a[i];
    }

    cout<<prod<<endl;    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}