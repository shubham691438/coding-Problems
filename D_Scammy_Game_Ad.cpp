#include <iostream>
#include <vector>
#include <string>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    
    vector<pair<char, char>> op(n + 1);
    vector<pair<int, int>> val(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        string op1, op2;
        int v1, v2;
        cin >> op1 >> v1 >> op2 >> v2;
        op[i] = {op1[0], op2[0]};
        val[i] = {v1, v2};
    }
    
    vector<int> latest_multiply(n + 2, 0);
    
    for (int i = n; i > 0; --i) {
        if (op[i].first == '+' && op[i].second == '+') {
            latest_multiply[i] = latest_multiply[i + 1];
        } else if (op[i].first == 'x' && op[i].second == '+') {
            latest_multiply[i] = 0;
        } else if (op[i].first == '+' && op[i].second == 'x') {
            latest_multiply[i] = 1;
        } else if (val[i].first > val[i].second) {
            latest_multiply[i] = 0;
        } else if (val[i].first < val[i].second) {
            latest_multiply[i] = 1;
        } else {
            latest_multiply[i] = latest_multiply[i + 1];
        }
    }
    
    vector<long long> a(2, 1);
    
    for (int i = 1; i <= n; ++i) {
        long long gained = 0;
        gained += (op[i].first == '+') ? val[i].first : (val[i].first - 1) * a[0];
        gained += (op[i].second == '+') ? val[i].second : (val[i].second - 1) * a[1];
        // cout<<"i = "<<i<<" latest_multiply[i + 1] = "<<latest_multiply[i + 1]<<endl;
        a[latest_multiply[i + 1]] += gained;
    }
    
    cout << (a[0] + a[1]) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}
