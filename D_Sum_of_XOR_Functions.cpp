#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order, order_of_key

#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(long long int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"

typedef long long int ll;
typedef vector<long long int> vi;
typedef vector<long long int> vll;
typedef pair<long long int, long long int> pi;
typedef pair<long long int, long long int> pll;

const int mod = 998244353;
ll ceil(ll n, ll k) {
  if (n % k == 0) {return n / k;}
  return (n / k) + 1;
}

bool isPrime(ll n) {
  for (ll i = 2; i <= sqrt(n); i++) {if (n % i == 0) {return false;} }
  return true;
}

vector<ll> getPrimes(ll n) {
  bool prime[n + 1] = {true};
  for (ll i = 2; i <= sqrt(n); i++) {
    if (prime[i] == true) {
      for (ll j = i * i; j <= n; j++) {
        prime[j] = false;
      }
    }
  }
  vector<ll>res;
  for (ll i = 2; i <= n; i++) {
    if (prime[i] == true) {res.push_back(i);}
  }
  return res;
}

bool isPalindrome(string s) {
  int n = s.size();
  for (int i = 0; i <= n / 2; i++) {
    if (s[i] != s[n - i - 1]) {return false;}
  }
  return true;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}

ll lcm(ll a, ll b) {ll product = a * b; ll g = gcd(a, b); return product / g;}

void yes(bool res) {if (res) { cout << "YES" << endl;} else { cout << "NO" << endl;} }

bool isSorted(vi v) {
// v0<=v1<=v2<=....<=vn
  ll n = v.size();
  rep(i, 1, n) {if (v[i] < v[i - 1]) { return false;} }
  return true;
}

ll Power(ll a, ll b) {
  ll result = 1; a %= mod;
  while (b) {if (b % 2 == 1) result *= a; a *= a; a %= mod; result %= mod; b /= 2; }
  return result;
}

ll Mod_Inv(ll a) {
  a %= mod; a = Power(a, mod - 2); return a;
}
bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{ return (a.second < b.second);}
const int N = 2e5 + 1;
vector<int>g[N];
bool visited[N];
ll fact[N];
void factorial() {
  fact[0] = 1;
  for (ll i = 1; i < N; i++) { fact[i] = i * fact[i - 1]; fact[i] %= mod; }
}

ll nCr(ll n, ll r)
{
  if (n < r) return 0;
  ll ans = fact[n]; ans %= mod;
  ans *= Mod_Inv(fact[r]); ans %= mod;
  ans *= Mod_Inv(fact[n - r]); ans %= mod;
  return ans;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  factorial();
  ll n;
  cin >> n;
  vi v(n);
  rep(i, 0, n) {
    cin >> v[i];
  }
  vector<vector<int>> b(33, vector<int>(n, 0));
  vector<vector<int>> demo(33, vector<int>(n, 0));
  rep(i, 0, 33) {
    rep(j, 0, n) {
      if ((v[j] >> i) & 1) {
        b[i][j] += 1;
        demo[i][j] += 1;
      }
    }
  }
  rep(i, 0, 33) {
    rep(j, 1, n) {
      demo[i][j] += demo[i][j - 1];
    }
  }

  ll ans = 0;
  rep(i, 0, 33) {
    ll cnt = 0;
    ll cnto = 0;
    ll cnte = 0;
    ll oi = 0;
    ll ei = 0;
    rep(j, 0, n) {
      if (demo[i][j] % 2) {
        cnto++;
        oi += (j + 1);
      } else {
        cnte++;
        ei += (j + 1);
      }
    }
    rep(j, 0, n) {
      if (demo[i][j] % 2) {
        cnto--;
        oi -= (j + 1);
      } else {
        cnte--;
        ei -= (j + 1);
      }
      if (b[i][j] % 2) {
        if (demo[i][j] % 2) {
          ll tsum = oi - (cnto * (j));
          cnt += tsum;
        } else {
          ll tsum = ei - (cnte * (j));
          cnt += tsum;
        }
        cnt%=mod;

      } else {
        if (demo[i][j] % 2) {
          ll tsum = ei - (cnte * (j));
          cnt += tsum;
        } else {
          ll tsum = oi - (cnto * (j));
          cnt += tsum;
        }
        cnt%=mod;

      }

    }
    
    ans = (ans + ((1LL << i) * cnt) % mod) % mod;

  }
  rep(i,0,n){
    ans=(ans+v[i])%mod;
  }
  cout << ans << endl;




}

