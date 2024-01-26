#include <bits/stdc++.h>
using namespace std;
#define  enl          '\n'
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    cin>>a;

    map<pair<int,int>,vector<array<int,3>>>mp;

    vector<int>ans(q);

    for(int i=0;i<q;i++) {
        int s,d,k;
        cin>>s>>d>>k;
        mp[{d,s%d}].push_back({s,k,i});
    }

    for(auto [pairr,vec]:mp) {
        auto [d,r] = pairr;
        if(r == 0) r = d;
        vector<int>pr,ap;
        for(int i=r;i<=n;i+=d) {
            pr.push_back(a[i-1]);
            ap.push_back(a[i-1]);
        }

        for(int i=1;i<sz(pr);i++) pr[i] += pr[i-1];
        for(int i=1;i<sz(ap);i++) ap[i] = ap[i]*(i+1)+ap[i-1];

        for(auto [s,k,i]:vec) {
            int st = (s-r)/d;
            ans[i] = ap[st+k-1];

            if(st) ans[i] -= ap[st-1]+st*(pr[st+k-1]-pr[st-1]);
        }
    }

    for(auto u:ans) cout<<u<<' ';cout<<enl;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases = 1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}