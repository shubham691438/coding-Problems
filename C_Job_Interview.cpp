#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int totalCandidates = n + m + 1;
    
    vector<int> a(totalCandidates);
    vector<int> b(totalCandidates);
    
    for (int i = 0; i < totalCandidates; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < totalCandidates; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> candidates(totalCandidates);
    for (int i = 0; i < totalCandidates; i++) {
        candidates[i] = {a[i], b[i]};
    }

    sort(candidates.begin(), candidates.end(), [](pair<int, int> &x, pair<int, int> &y) {
        return x.first - x.second > y.first - y.second;
    });

    vector<long long> prefixProgrammer(totalCandidates + 1, 0);
    vector<long long> prefixTester(totalCandidates + 1, 0);

    for (int i = 0; i < totalCandidates; i++) {
        prefixProgrammer[i + 1] = prefixProgrammer[i] + candidates[i].first;
        prefixTester[i + 1] = prefixTester[i] + candidates[i].second;
    }
    for (int i = 0; i < totalCandidates; i++) {
        int pLeft = n, tLeft = m;
        long long teamSkill = 0;

        if (i < n) {
            pLeft--;
            teamSkill += prefixProgrammer[i] + (prefixProgrammer[totalCandidates] - prefixProgrammer[i + 1]);
        } else {
            tLeft--;
            teamSkill += prefixTester[i] + (prefixTester[totalCandidates] - prefixTester[i + 1]);
        }

        for (int j = 0; j < totalCandidates; j++) {
            if (j == i) continue;
            if (pLeft > 0 && (candidates[j].first >= candidates[j].second || tLeft == 0)) {
                teamSkill += candidates[j].first;
                pLeft--;
            } else {
                teamSkill += candidates[j].second;
                tLeft--;
            }
        }

        cout << teamSkill << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
