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
    ll n,m;
    cin>>n>>m;

    vector<vector<char>> a(n,vector<char> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }    

    bool possible=true;

    //for each row, need to take care of the vertical dominons;
   for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='U')
            {
                cnt++;

                if(cnt%2==1)
                {
                    a[i][j]='W';
                    a[i+1][j]='B';
                }
                else
                {
                    a[i][j]='B';
                    a[i+1][j]='W';
                }
            }          
        }

        if(cnt%2==1)
            possible=false;
    }    


    //for each col, need to take care of the horizontal dominons;
   for(int i=0;i<m;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(a[j][i]=='L')
            {
                cnt++;

                 if(cnt%2==1)
                {
                    a[j][i]='W';
                    a[j][i+1]='B';
                }
                else
                {
                    a[j][i]='B';
                    a[j][i+1]='W';
                }
            }

           
        }

        if(cnt%2==1)
            possible=false;
    }  


    if(!possible)
    {
        cout<<-1<<endl;
        return ;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }  




}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}