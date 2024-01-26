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
    ll n,k;
    cin>>n>>k;

    vector<int> a(n),h(n);
    for(auto &x:a) cin>>x;
    for(auto &x:h) cin>>x;

    int i=0,j=0,sum=0,ans=0;
    while(j<n)
    {
        sum+=a[j];
        if(sum<=k && h[j==i? j:j-1]%h[j] ==0)
        {
            
            ans=max(ans,j-i+1);
            j++;

        }
        else if(  (sum>k && h[j==i? j:j-1]%h[j] ==0 ) )
        {
            while(sum>k)
            {
                sum-=a[i];
                i++;

                if(sum<=k)
                ans=max(ans,j-i+1);
                
            }
            if(sum<=k)
                ans=max(ans,j-i+1);

            j++;
        }
        else
        {
            sum=0;
            
            
            i=j;
        }
        

    }

    cout<<ans<<endl;


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}