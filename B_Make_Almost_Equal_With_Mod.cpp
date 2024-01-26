#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second
#define w(t) ll t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb push_back
/*-----------------------------------------------------------------------------------*/

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(auto &x : a) cin >> x;


    
    ll ans = -1;
    
    for(ll i = 2; ; i = i * 2)
    {
        set<ll> st;
        for(int j = 0; j < n; j++)
        {
           st.insert(a[j]%i);
        }

        if(st.size()==2)
        {
            ans=i;
            break;
        }
    }

    

    cout << ans << endl;
    // for(int i = 0; i < n; i++)
    //     cout << a[i] % ans << " ";
    // cout << endl;
}


int main(){
    fastio
    w(t){
        solve();
    }
}
