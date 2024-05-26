#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Define a type for long long
typedef long long ll;

int solve(vector<vector<int>>& dp, vector<int>& v, int i, int j, int k) {
    if (i > j) return 0;
    if (dp[i][j] != INT_MIN) return dp[i][j];

    int first = 0, last = 0, ans = 0;
    if (k % 2 == 0) {
        first = v[i] + solve(dp, v, i + 1, j, k + 1); 
        last = v[j] + solve(dp, v, i, j - 1, k + 1); 
        ans = max(first, last); 
    } else { 
        first =  solve(dp, v, i + 1, j, k + 1); 
        last =  solve(dp, v, i, j - 1, k + 1); 
        ans = min(first, last); 
    }
    return dp[i][j] = ans;
}

int helper(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    return solve(dp, v, 0, n - 1, 0); 
}

void solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    cout << helper(a) << endl;
}

int main() {
    solve();
    return 0;
}
