#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000000
#define mod LLONG_MAX
#define endl "\n"
#define ff first
#define ss second
#define w(t) ll t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb push_back
/*-----------------------------------------------------------------------------------*/

void solve() {
    char ans;
    string str;
    for(int i = 0; i < 3; i++) {
        cin >> str;
        ll sum = 'A' + 'B' + 'C';
        if(str.find('?') != string::npos) {
            for(int j = 0; j < 3; j++) {
                if(str[j] != '?') {
                    sum -= str[j];
                }
            }
            ans = sum;
            cout << ans;
        }
    }
    cout << endl;
}

int main() {
    fastio
    w(t) {
        solve();
    }
    return 0;
}
