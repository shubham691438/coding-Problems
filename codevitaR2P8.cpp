#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int budget;
    cin >> budget;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(budget + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= budget; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];

                if (k >= prices[i - 1] && j < 2) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k - prices[i - 1]] + values[i - 1]);
                }
            }
        }
    }

    int maxTotalValue = 0;
    for (int k = 0; k <= budget; ++k) {
        maxTotalValue = max(maxTotalValue, dp[n][0][k]);
    }

    if (maxTotalValue == 0) {
        cout << "Insufficient Budget" << endl;
    } else {
        cout << maxTotalValue << endl;
    }

    return 0;
}
