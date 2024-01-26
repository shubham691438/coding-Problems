#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      mod        998244353
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
    vector<int> x(n),ex(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>ex[i];

    ll m;
    cin>>m;
    vector<int> y(m),ey(m);
    for(int i=0;i<m;i++) cin>>y[i];
    for(int i=0;i<m;i++) cin>>ey[i];

    unordered_set<int> st;
    unordered_map<int,int> expoX,expoY;

    for(int i=0;i<n;i++)
    {
        expoX[x[i]]=ex[i];
        st.insert(x[i]);
    }
    for(int i=0;i<m;i++)
    {
        expoY[y[i]]=ey[i];
        st.insert(y[i]);
    }

    ll ans=1;
    for(auto p:st)
    {
        
        if(expoX[p]<expoY[p])
        {
            ans=0;
            break;
        }
        else if(expoX[p]==expoY[p])
        {
            ans=ans*1;
        }
        else
        {
            ans=(ans*2)%mod;
        }
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    
        solve();
   
}