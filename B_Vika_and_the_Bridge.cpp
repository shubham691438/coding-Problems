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
    ll n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    //geting the max_step and second_max step for each color;
    vector<int> last(k+1,-1);
    vector<int> max_step(k+1,0),second_max(k+1,0);

    for(int i=0;i<n;i++)
    {
        int step=i-last[a[i]];
        // cout<<step<<endl;
        if(step > max_step[a[i]])
        {
            second_max[a[i]]=max_step[a[i]];
            max_step[a[i]]=step;
        }
        else if(step>second_max[a[i]])
        {
            second_max[a[i]]=step;
        }

        last[a[i]]=i;
    }   

    // for the last step of each color
    for(int i=0;i<k;i++) 
    {
        int step=n-last[i+1];
        if(step > max_step[i+1])
        {
            second_max[i+1]=max_step[i+1];
            max_step[i+1]=step;
        }
        else if(step>second_max[i+1])
        {
            second_max[i+1]=step;
        }
    }

    int ans=1e9;
    for (int i = 0; i < k; ++i) {
        ans = min(ans, max((max_step[i+1] + 1) / 2, second_max[i+1]));
    }
    cout<<ans-1<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}