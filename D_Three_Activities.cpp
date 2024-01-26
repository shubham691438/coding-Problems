//https://www.youtube.com/watch?v=BwAp2sM8858 

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
    
    vector<int> a(n),b(n),c(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    for(auto &x:c) cin>>x;

    set<pair<int,int>> setb,setc;
    for(int i=0;i<n;i++)
    {
        setb.insert({b[i],i});
        setc.insert({c[i],i});
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        setb.erase({b[i],i});
        setc.erase({c[i],i});

        if( (*setb.rbegin()).ss == (*setc.rbegin()).ss)
        { 
            //max from b and second max from c  OR vice versa 
            ans=max(ans,a[i]+ max(  (*setb.rbegin()).ff + (*(--(--setc.end()))).ff , (*setc.rbegin()).ff + (*(--(--setb.end()))).ff ));
        }
        else
        {
            ans=max(ans,a[i]+(*setb.rbegin()).ff+(*setc.rbegin()).ff);
        }

        setb.insert({b[i],i});
        setc.insert({c[i],i});
    }

    cout<<ans<<endl;


    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}