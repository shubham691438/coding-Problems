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

   string str;
   cin>>str;
    
    map<char,ll> mp;
    for(ll i=0;i<n;i++)
    {
       mp[str[i]]++;
    }

    ll max_cnt=0;
    for(auto it:mp)
    {
        if(it.ss>max_cnt)
        {
            max_cnt=it.ss;
        }
    }
    
    if(n&1 || max_cnt>n/2)
    {
        cout<<-1<<endl;
        return;
    }

    map<char,ll> equals;
    ll equal_pair=0,mx=0;
    for(ll i=0;i<n/2;i++)
    {
        if(str[i]==str[n-i-1])
        {
            equal_pair++;
            equals[str[i]]++;
            mx=max(equals[str[i]],mx);
        }
    }


    if(2*mx>equal_pair)
    {
        cout<<mx<<endl;
        return;
    }
    if(equal_pair&1)
    {
        cout<<equal_pair/2+1<<endl;
    }
    else
    {
        cout<<equal_pair/2<<endl;
    }


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}