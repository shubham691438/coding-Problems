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
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n,m;
    cin>>n>>m;

    vector<vector<char>> mat(n, vector<char>(m)); // Initialize the vector with correct dimensions
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];

    string str="vika";
    int pos=0;
    for(int i=0;i<m;i++)
    {
        bool f=false;
        for(int j=0;j<n;j++)
        {
            if(mat[j][i]==str[pos]) {
                f=true;
                break; // Exit the loop as soon as we find a match
            }
        }  

        if(f)
            pos++; 
    }

    if(pos==4)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
             
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}
