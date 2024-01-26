//https://youtu.be/xKsGZNIpdtY?t=1123
//https://www.youtube.com/watch?v=tHo5UwJtuMg&t=12s


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
    ll n;
    cin>>n;

    vector<vector<int>> mat(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char c;
            cin>>c;
            mat[i][j]= c-'0';
        }

    //    for(int i=1;i<=n;i++)
    //    {
    //         for(int j=1;j<=n;j++)
    //         {
    //             cout<<mat[i][j]<<" ";
    //         }
    //         cout<<endl;
    //    }
        
    vector<int> start(n+2,0),end(n+2,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        vector<int> f(n+2,0);
        f[0]=start[0];
        for(int j=1;j<=n;j++)
        {
            f[j]=f[j-1]+start[j]-end[j-1];
        }
        f[n+1]=end[n+1];

        vector<int> nextStart(n+2,0),nextEnd(n+2,0);
        nextStart[0]=start[0];
        nextEnd[n+1]=end[n+1];

        for(int j=1;j<=n;j++)
        {
            if(mat[i][j]==1 && (f[j]%2==0) )
            {
                ans++;
                nextStart[j-1]++;
                nextEnd[j+1]++;
            }
            else if(mat[i][j]==0 && (f[j]%2==1))
            {
                ans++;
                nextStart[j-1]++;
                nextEnd[j+1]++;
            }
        }

        for(int j=0;j<n+2;j++)
        {
            if(j+1 < n+2) nextStart[j]+=start[j+1];
            if(j-1>-1) nextEnd[j]+=end[j-1];
        }

        start=nextStart;
        end=nextEnd;

    }

    cout<<ans<<endl;

             


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}