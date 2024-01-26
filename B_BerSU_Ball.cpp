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

    vector<int> b(n,111);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }    

    sort(b.begin(),b.end());
    int m;
    cin>>m;
    vector<int> g(m,111);
    for(int i=0;i<m;i++)
    {
        cin>>g[i];
    }

    sort(g.begin(),g.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i]-1==g[j] || b[i]+1==g[j] || b[i]==g[j])
            {
                // cout<<i<<" "<<j<<endl;
                // cout<<b[i]<<" "<<g[j]<<endl;
                // cout<<endl;
                ans++;
                g[j]=111;
                b[i]=-111;
            }
            
        }
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    // w(t){
        solve();
    // }
}