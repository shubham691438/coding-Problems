#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

bool canTransform(vector<vector<int>> a, vector<vector<int>> b, int n, int m) {
    // Sort each row of both matrices
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            return false;
    }

    // Transpose both matrices to sort columns
    vector<vector<int>> a_transposed(m, vector<int>(n));
    vector<vector<int>> b_transposed(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a_transposed[j][i] = a[i][j];
            b_transposed[j][i] = b[i][j];
        }
    }

    // Sort each column of the transposed matrices
    for (int i = 0; i < m; ++i) {
        sort(a_transposed[i].begin(), a_transposed[i].end());
        sort(b_transposed[i].begin(), b_transposed[i].end());
    }
   
     for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j << m; ++j)
                cin >> b[i][j];

        if (canTransform(a, b, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
