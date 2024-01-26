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
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    unordered_map<ll,vector<ll>> mp;
    for(ll i=0;i<n;i++)
    {
        mp[a[i]].push_back(i);
    }    

    ll minDays=1e9;
    vector<ll> clans;
    for(auto ele:mp)
    {
        ll  num=ele.first;
        vector<ll> arr=ele.second;

        ll sz=arr.size();
        ll maxi=0;
        
        maxi=max(maxi,arr[0]);
        maxi=max(maxi,n-arr[sz-1]-1);

        for(ll i=1;i<sz;i++)
        {
            ll inbetween=arr[i]-arr[i-1]-1;
            ll days=ceil((double)inbetween/2);
            maxi=max(maxi,days);

        }
        if(maxi<minDays)\
        {
            minDays=maxi;
            clans.clear();
            clans.push_back(num);
        }
        else if(maxi==minDays)
        {
            clans.push_back(num);
        }

    }

    sort(clans.begin(),clans.end());
    cout<<clans[0]<<" "<<minDays<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}