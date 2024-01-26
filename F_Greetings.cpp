#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000000
#define mod LLONG_MAX
#define endl "\n"
#define ff first
#define ss second
#define w(t) ll t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb push_back

bool comparator(pair<ll, ll> x, pair<ll, ll> y)
{
    return x.second < y.second;  
}

ll bs(vector<ll>& v, ll key)
{
    ll ans = 0;
    ll l = 0, r = v.size() - 1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (v[mid] >= key)
        {
            ans = mid + 1;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> vp;
    vector<ll> v;

    for (int i = 0; i < n; i++) 
    {
        ll a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }

    sort(vp.begin(), vp.end(), comparator);

    ll ans = 0;

    v.push_back(vp[0].first);

    for (int i = 1; i < n; i++)
    {
        ll a = vp[i].first;
        ll b = vp[i].second;

        ll num = bs(v, a);
        v.push_back(a);

        ans += num;
    }

    cout << ans << endl;
}

int main()
{
    fastio
    w(t)
    {
        solve();
    }
}
