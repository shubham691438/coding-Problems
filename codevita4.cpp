#include <bits/stdc++.h>
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

struct PolarVector {
    double magnitude;
    double angle;

    PolarVector() : magnitude(0.0), angle(0.0) {}  // Default constructor

    PolarVector(double mag, double ang) : magnitude(mag), angle(ang) {}
};

PolarVector addPolarVectors(const PolarVector& v1, const PolarVector& v2) {
    double x1 = v1.magnitude * cos(v1.angle * M_PI / 180.0);
    double y1 = v1.magnitude * sin(v1.angle * M_PI / 180.0);

    double x2 = v2.magnitude * cos(v2.angle * M_PI / 180.0);
    double y2 = v2.magnitude * sin(v2.angle * M_PI / 180.0);

    double xResult = x1 + x2;
    double yResult = y1 + y2;

    double magResult = sqrt(xResult * xResult + yResult * yResult);
    double angResult = atan2(yResult, xResult) * 180.0 / M_PI;

    return PolarVector(magResult, angResult);
}

map<ll, PolarVector> dis;
set<ll> vis;

void bfs(ll src, vector<pair<ll, PolarVector>> adj[]) {
    queue<ll> q;
    vis.insert(src);
    dis[src] = {0, 0};

    q.push(src);

    while (!q.empty()) {
        ll node = q.front();
        q.pop();

        for (auto child : adj[node]) {
            if (vis.find(child.first) == vis.end()) {
                vis.insert(child.first);

                PolarVector pv2 = child.second;
                dis[child.first] = addPolarVectors(dis[node], pv2);

                q.push(child.first);
            }
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vp;
    for (int i = 0; i < n; i++) {
        char c;
        ll x, y;
        cin >> x >> c >> y;
        vp.push_back({x, y});
    }

    vector<pair<ll, PolarVector>> adj[n + 1];
    for (int i = 0; i < n; i++) {
        ll u;
        cin >> u;
        for (int j = 0; j < vp[i].second; j++) {
          ll v, mag, angle;
          cin >> v >> mag >> angle;

          PolarVector vec = {static_cast<double>(mag), static_cast<double>(angle)};
          adj[u].push_back({v, vec});
      }
    }

    ll start, end;
    cin >> start >> end;

    bfs(start, adj);

    cout << fixed << setprecision(2) << dis[end].magnitude << endl;
}

int main() {
    fastio
    solve();
    return 0;
}
