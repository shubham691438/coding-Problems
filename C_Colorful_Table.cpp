#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];

        vector<bool> visited(k+1,false);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            visited[arr[i]]=true;
        }


        vector<ll> prefix;
        vector<ll> suffix;

        ll mx=0;

        for(ll i=0;i<n;i++){
            mx=max(mx,arr[i]);

            prefix.push_back(mx);
        }

        mx=0;

        for(ll i=n-1;i>=0;i--){
            mx=max(mx,arr[i]);
            suffix.push_back(mx);

        }


        for(ll i=1;i<=k;i++){

            if(!visited[i]){
                cout<<"0 ";
                continue;
            }


            auto it=lower_bound(prefix.begin(),prefix.end(),i);
            ll start=it-prefix.begin();

            // reverse(suffix.begin(),suffix.end());
            auto it1=lower_bound(suffix.begin(),suffix.end(),i);
            ll end=it1-suffix.begin();

            end=n-1-end;

            ll val=(end-start+1);
            val*=2;

            cout<<val<<" ";
        }
        cout<<endl;












    }
    return 0;
}