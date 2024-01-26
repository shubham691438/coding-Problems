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

bool compare(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.ss==1 && b.ss==1)
    {
        if(a.ff>b.ff)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(a.ss==1)
    {
        return true;
    }
    else if(b.ss==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void solve(){
    ll n,k;
    cin>>n>>k;

    vector<pair<ll,ll>> seg(n);
    for(ll i=0;i<n;i++)
    {
        cin>>seg[i].ff;
    }  
    for(ll i=0;i<n;i++)
    {
        cin>>seg[i].ss;
    }   

   vector<pair<ll,ll>> diff(n);
   for(ll i=0;i<n;i++)
   {
    diff[i].ff=seg[i].ss-seg[i].ff+1;
    diff[i].ss=0;
   }  

   ll sum=0;
   for(ll i=0;i<n;i++)
   {
        if(sum<k)
        {
            sum+=diff[i].ff;
            diff[i].ss=1;
        }
        else
        {
            break;
        }
   }

   sort(diff.begin(),diff.end(),compare);
   for(ll i=0;i<n;i++)
   cout<<diff[i].ff<<" ";

   cout<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}