#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto &i : a) cin >> i;
    
    sort(a.begin(), a.end());

    int allLCM=1;
    for(int i=0;i<n;i++)
    {
        allLCM=allLCM*a[i]/__gcd(allLCM,a[i]);
         if(allLCM>a[n-1])
        {
            cout<<n<<endl;
            return;
        }
    }

   

    
    map<int, int> freq;
    for (const auto &val : a) {
        freq[val]++;
    }
    
    vector<int> unique_vals;
    for (const auto &p : freq) {
        unique_vals.push_back(p.first);
    }
    
    int ans = 0;
    int num_unique = unique_vals.size();

    
    
    for (int i = num_unique - 1; i >= 0; --i) {
        int cur = unique_vals[i];
        int len = freq[cur];
        bool exceed = false;
        
        for (int j = i - 1; j >= 0; --j) {
            int lcm = cur * unique_vals[j] / __gcd(cur, unique_vals[j]);
            
            if (freq[lcm] > 0 && lcm != cur) continue;
            len += freq[unique_vals[j]];
            cur = lcm;
            
            if (freq.find(cur) == freq.end()) {
                ans = max(ans, len);
            }
        }
        
        
        
        if (len > 1 && freq[cur] == 0) {
            ans = max(ans, len);
        }
        
        if (ans == n) break;
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
