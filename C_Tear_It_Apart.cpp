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

    ll n=str.size();
    ll minofall=n;
    for(ll i=0;i<26;i++)
    {
        char ch='a'+i;
        ll len=0,maxlen=0;
        for(ll j=0;j<n;j++)
        {
            if(str[j]==ch)
            {
                maxlen=max(len,maxlen);
                len=0;
            }
            else
            {
                len++;
            }
        }
        maxlen=max(len,maxlen);
        minofall=min(maxlen,minofall);
    }

    if(minofall==0)
    {
        cout<<0<<endl;
        return;
    }
    cout<<floor(log2(minofall)+1)<<endl;


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}