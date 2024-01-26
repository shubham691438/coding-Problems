#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

 
 
void solve() {
    string str;
    cin >> str;

    int n = str.size();

    string str1 = string(1, str[0]);

    int i = 1;
    while (i < n && str[i] == '0') {
        str1 += str[i];
        i++;
    }

    string str2 = (i < n) ? str.substr(i, n - i) : "0";

    int a = stoi(str1);
    int b = stoi(str2);

    if (b > a && b != 0 ) {
        cout << a << " " << b << endl;
    } else {
        cout << -1 << endl;
    }
}

 
 
int main(){
    fastio
    w(t){
        solve();
    }
}