#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // DP table: dp[k] will be the maximum health achievable by taking exactly k potions
    vector<long long> dp(n + 1, LLONG_MIN);
    dp[0] = 0; // Base case: 0 potions taken, health is 0

    int max_potions = 0;

    for (int i = 0; i < n; ++i) {
        for (int k = n; k >= 0; --k) {
            if (dp[k] != LLONG_MIN && dp[k] + a[i] >= 0) {
                dp[k + 1] = max(dp[k + 1], dp[k] + a[i]);
                max_potions = max(max_potions, k + 1);
            }
        }
    }

    cout << max_potions << endl;

    return 0;
}
