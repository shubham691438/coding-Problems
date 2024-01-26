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

int lengthOf(string& str,int k) {
    int n = str.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if ( abs(str[i] - str[j]) <=k && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    return *max_element(dp.begin(), dp.end());
}
 
void solve(){
    ll n,k;
    cin>>n>>k;

    string str;
    cin>>str;

    cout<<lengthOf(str,k)<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}