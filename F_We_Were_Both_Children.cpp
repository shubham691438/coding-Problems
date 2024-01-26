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
    int n;
    cin>>n;
    vector<int> a(n),cnt(n+1,0),mx(n+1,0);
    for(int i=0;i<n;i++){
         cin>>a[i];

         if(a[i]<=n)
            cnt[a[i]]++;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            mx[j]+=cnt[i];


    for(int i=1;i<=n;i++)
        ans=max(mx[i],ans);

    cout<<ans<<endl;            
    
    }
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}