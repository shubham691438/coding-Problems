//https://codeforces.com/blog/entry/120634

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

 
 
void solve(){
	string s;
	cin >> s;
	int n = s.length(), cnt = 0;
	bool all = (s[0] == 'B' || s[n - 1] == 'B');
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1] && s[i] == 'B') {all = true;}
	}
	vector<int> lens;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {curr++;}
		else {
			if (curr != 0) {lens.push_back(curr);}
			curr = 0;
		}
	}
	if (curr != 0) {lens.push_back(curr);}
	sort(lens.begin(), lens.end());
	
	if (lens.empty()) {cout << 0 << '\n'; return;}
	
	int tot = 0;
	if (all) {tot += lens[0];}
	for (int i = 1; i < lens.size(); i++) {
		tot += lens[i];
	}
	cout << tot << '\n';

}
 
 
int main(){
	fastio
	w(t){
		solve();
	}
}