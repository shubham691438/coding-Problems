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
    ll min11=1e9,min10=1e9,min01=1e9;
    for(ll i=0;i<n;i++)
    {
        ll t;
        string skill;
        cin>>t>>skill;

        if(skill=="11")
        {
            min11=min(t,min11);
        }
        else if(skill=="10")
        {
            min10=min(min10,t);
        }
        else if(skill=="01")
        {
            min01=min(min01,t);
        }
    }

    if((min11==1e9 && min10==1e9) || (min11==1e9 && min01==1e9))    
    {
        cout<<-1<<endl;
        return;
    }

    cout<<min(min11,min10+min01)<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}