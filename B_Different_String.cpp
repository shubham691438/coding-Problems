#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	string s;
	cin >> s;
	bool ok = false;
	for (int i = 1; i < (int)(s.length()); i++) {
		if (s[i] != s[0]) {swap(s[i], s[0]); ok = true; break;}
	}	
	if (!ok) {
		cout << "NO\n"; return;
	}
	cout << "YES\n";
	cout << s << '\n';
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	
}