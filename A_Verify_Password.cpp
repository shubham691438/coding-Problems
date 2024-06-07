#include <bits/stdc++.h>
using namespace std;

// Function to check if the string is a strong password
bool isStrongPassword(const string& password) {
    string letters, digits;
    int n = password.size();

    // Split the password into letters and digits
    for (int i = 0; i < n; ++i) {
        if (isdigit(password[i])) {
            digits.push_back(password[i]);
        } else {
            letters.push_back(password[i]);
        }
    }

    // Check if letters are in non-decreasing order
    if (!is_sorted(letters.begin(), letters.end())) {
        return false;
    }

    // Check if digits are in non-decreasing order
    if (!is_sorted(digits.begin(), digits.end())) {
        return false;
    }

    // Ensure no digit comes after a letter
    for(int i=0;i<password.size()-1;i++)
    {
        if(isalpha(password[i]) && isdigit(password[i+1]))
        {
            return false;
        }
    }

    return true;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string password;
        cin >> password;
        
        if (isStrongPassword(password)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
