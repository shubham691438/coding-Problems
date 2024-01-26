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

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];


    ll maxDiff=0;
    for(int i=1;i<n/2+1;i++)
    {
        if(n%i==0)
        {
            ll maxSum=0,minSum=LLONG_MAX,sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=a[j];
                if((j+1)%i==0)
                {
                    maxSum=max(maxSum,sum);
                    minSum=min(minSum,sum);
                    sum=0;
                }
            }

            // cout<<maxSum<<" "<<minSum<<endl;

            maxDiff=max(maxDiff,maxSum-minSum);
        }
    }   

    cout<<maxDiff<<endl;  
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}