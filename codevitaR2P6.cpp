#include <bits/stdc++.h>
using namespace std;

const int M = 5;
const int N = 10001;

int main() {
    int t;
    cin >> t;

    int h[M];
    for (int &x : h) {
        cin >> x;
    }

    sort(h, h + M, greater<int>());

    vector<int> dp(N, -1);
    dp[0] = 0;

    for (int i = 1; i <= t; ++i) {
        for (int j : h) {
            if (i - j >= 0 && dp[i - j] != -1) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }

    if (dp[t] == -1) {
        cout << "Impossible";
        return 0;
    }

    map<int, int> m;
    while (t > 0) {
        for (int j : h) {
            if (t - j >= 0 && dp[t] == dp[t - j] + 1) {
                m[j]++;
                t -= j;
                break;
            }
        }
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i].first;
        if (i < v.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
