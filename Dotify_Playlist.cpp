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
    ll n,k,l;
    cin>>n>>k>>l;

    vector<int> pl;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(b==l)
        {
            pl.push_back(a);
        }
    }    

    if(pl.size()<k)
    {
        cout<<-1<<endl;
        return;
    }

    sort(pl.begin(),pl.end(),greater<int>());
    int ans=0;
    for(int i=0;i<k;i++)
        ans+=pl[i];

    cout<<ans<<endl;
        
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}