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
    ll n;
    cin>>n;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        vector<int> temp=permutation;
        reverse(temp.begin()+i,temp.end());

        int curr=0;
        int maxi=0;
        for(int j=0;j<n;j++)
        {
            curr+=temp[j]*(j+1);
            maxi=max(maxi,temp[j]*(j+1));
        }

        ans=max(ans,curr-maxi);
        
    }

    cout<<ans<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}