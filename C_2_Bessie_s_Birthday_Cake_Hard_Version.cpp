#include<bits/stdc++.h>
using namespace std;
 
// DEBUG CODE 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



#define      ll         long long
#define      MAX        1000000
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

 
 //REFER TO EDITORIAL
void solve(){
	int n, x, y; cin >> n >> x >> y;
	int initial_y = y;
	vector<int> chosen(x);
	for(int& i: chosen) cin >> i;
	sort(chosen.begin(), chosen.end());
	int ans = x - 2;


	int triangles_from_even_g = 0;
	vector<int> odd_g;

	auto process_gap = [&](int g) -> void{
        if (g==0) return;

		if(g == 1){
			// already two apart
			ans++;
		}
		else if(g % 2 == 1){
			odd_g.push_back(g / 2);
		}
		else{
			triangles_from_even_g += g / 2;
		}
	};


	for(int i = 0; i < x - 1; i++){
		process_gap(chosen[i + 1] - chosen[i] - 1);
	}

	process_gap((chosen[0] + n) - chosen[x - 1] - 1);
    
    
    //process the smallest first
	sort(odd_g.begin(), odd_g.end());
	for(int g: odd_g){
		if(y >= g){
			// all vertices are good, so we can make g + 1 triangles
			ans += g + 1;
			y -= g;
		}
		else{
			ans += y;
			y = 0;
			break;
		}
	}

   
	int even_triangles = min(triangles_from_even_g, y);
	y -= even_triangles;
	ans += even_triangles;

    
	// int used_vertices = initial_y - y;
	// ans += used_vertices;
	cout << ans << "\n";
}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}