#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), cnt(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        
        long long ans = 0;
        int smaller = 0;
        
        for (int i = 0; i <= n; i++) {
            ans += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2 * smaller;
            smaller += cnt[i];
        }
        
        cout << ans << endl;
    }
    
    return 0;
}