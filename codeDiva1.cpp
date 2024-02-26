#include <bits/stdc++.h>
#define N 200050
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
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

 

int n, A[N], cont, q, freq[N], L, R, ans[N], sqn, tree[4*N], qtd[4*N], resp;

vector<int> v;

map<int, int> comp;

struct S
{
	int i, j, id;
};

bool f(S A, S B)
{
	if(A.i / sqn < B.i / sqn) return true;
	if(A.i / sqn > B.i / sqn) return false;
	return A.j < B.j ;
}

S Q[N];

void compress()
{
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		int x = v[i];

		if(!comp[x]) comp[x] = ++cont;
	}

	for(int i = 1; i <= n; i++) A[i] = comp[A[i]];
}

void add(int i)
{	
	qtd[freq[A[i]]] --;

	freq[A[i]] ++;

	qtd[freq[A[i]]] ++;

	if(qtd[resp + 1]) resp ++;
}
void remove(int i)
{
	qtd[freq[A[i]]] --;

	freq[A[i]]--;

	qtd[freq[A[i]]] ++;
	
	if(resp > 0 && !qtd[resp]) resp --;
}

int query(int k)
{
	while(L < Q[k].i)
	{
		remove(L);

		L++;
	}

	while(L > Q[k].i)
	{
		L --;

		add(L);
	}

	while(R < Q[k].j)
	{
		R ++;

		add(R);
	}

	while(R > Q[k].j)
	{
		remove(R);

		R --;
	}

    if(resp > (Q[k].j-Q[k].i+1)/2) return -1;
	return resp;
}

void solve()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n>>q;

	sqn = sqrt(n);

	for(int i = 1; i <= n; i++) cin>>A[i], v.push_back(A[i]);

	compress();

	for(int i = 1; i <= q; i++)
	{
		cin>>Q[i].i>>Q[i].j;

		Q[i].i, Q[i].j;

		if(Q[i].j < Q[i].i) swap(Q[i].i, Q[i].j);

	 	Q[i].id = i;
	 }

	sort(Q + 1, Q + q + 1, f);

	for(int i = 1; i <= q; i++) ans[Q[i].id] = query(i);

	for(int i = 1; i <= q; i++) 
    {
        if(ans[i]==-1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}

int main(){
    fastio
    w(t){
        solve();
    }
}