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
    vector<int> s(n),e(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>e[i];
    }    

    int ans=s[0];
    bool possible=true;
    for(int i=1;i<n;i++)
    {
        if(s[i]>=s[0] && e[i]>=e[0])
        {
            possible =false;
            break;
        }
    }

    if(possible)
    {
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}