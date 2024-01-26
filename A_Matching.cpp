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
    string str;
    cin>>str;

    ll cntq=0;
    for(ll i=0;i<str.size();i++)
    {
        if(str[i]=='?')
        {
            cntq++;
        }
    }

    if(str[0]=='0')
    {
        cout<<0<<endl;
        return;
    }
    if(cntq==0)
    {
        
            cout<<1<<endl;
            return;
    }

    bool non_zero=false;
    for(ll i=0;i<str.size();i++)
    {
        if(str[i]!='0' && str[i]!='?')
        {
            non_zero=true;
            break;
        }

        if(str[i]=='?')
        {
            break;
        }
    }

    if(non_zero)
    {
        ll ans=1;
        for(ll i=0;i<cntq;i++)
        {
            ans=ans*10;
        }
        cout<<ans<<endl;
    }
    else{
        ll ans=9;
        for(ll i=0;i<cntq-1;i++)
        {
            ans=ans*10;
        }
        cout<<ans<<endl;
    }  
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}