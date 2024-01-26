#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    ll ans = 0;
    vector<vector<ll>> cnt(6, vector<ll>(46, 0));

    for (const string& str : s) {
        ll sum = 0;
        for (char c : str) {
            sum += c - '0';
        }
        cnt[str.length()][sum] += 1;
    }

    for(string &L:s)
    {
        for(ll lenr=L.length()%2;lenr<=L.length();lenr+=2)
        {
            ll l=L.length()+lenr;

            ll suml=0,sumr=0;
            for(ll i=0;i<l/2;i++)
                suml+=L[i]-'0';

            for(ll i=l/2;i<L.length();i++)
                sumr+=L[i]-'0';

            if(suml-sumr>=0)
                ans+=cnt[lenr][suml-sumr];    
               
        }
    }

    for (const string& R : s) {
        for (ll lenl = R.length() % 2; lenl < R.length(); lenl += 2) {
            ll l = R.length() + lenl;
            ll suml = 0, sumr = 0;

            for (ll i = R.length() - l / 2; i < R.length(); ++i) {
                suml += R[i] - '0';
            }

            for (ll i = 0; i < R.length() - l / 2; ++i) {
                sumr += R[i] - '0';
            }

            if (suml - sumr >= 0) {
                ans += cnt[lenl][suml - sumr];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
