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

 
 
void solve(){
    ll n,m;
    cin>>n>>m;

   
     // Create a 2D vector to store the matrix
    vector<vector<int>> matrix(n, vector<int>(m,1e9));

    // Populate the matrix with the desired values
    for (int i = 0; i < min(m-1,n); ++i) {
        for (int j = 0; j < m  ; ++j) {

            // if((i + j) % m == m-j-1)
            matrix[i][j] = (i + j) % m;
        }
    }

    if(n>=m)
    {
        for (int i = m-1; i < n; ++i) {
            ll curr=0;
            for (int j = 0; j < m  ; ++j) {
                matrix[i][j] = curr++;
            }
        }
    }


    vector<ll> mexRow;
    for(int i=0;i<m;i++){
        
        ll currMex=0;
        vector<int> col;
        for(int j=0;j<n;j++)
        {
            col.push_back(matrix[j][i]);
        }

        sort(all(col));
        for(int j=0;j<n;j++){
            if(col[j]==currMex){
                currMex++;
            }
        }

        mexRow.push_back(currMex);
    }

    // debug(mexRow);
    sort(all(mexRow));
    ll finalMex=0;
    for(int i=0;i<m;i++){
        if(mexRow[i]==finalMex){
            finalMex++;
        }
    }

    cout<<finalMex<<endl;
    //  Print the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}