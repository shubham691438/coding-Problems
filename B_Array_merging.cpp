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
    int n;
    cin>>n;

    vector<int> a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    map <int,int> mp1,mp2;

    int cnt=1;
    mp1[a[0]]=1;
    int i;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            cnt++;
        }
        else
        {
            if(mp1[a[i-1]]<cnt)
            {
                mp1[a[i-1]]=cnt;
            }
            cnt=1;
        }
    }

    if(mp1[a[n-1]]<cnt)
            {
                mp1[a[n-1]]=cnt;
                cnt=1;
            }

    // for(auto x:mp1) cout<<x.first<<" --> "<<x.second<<endl;
    // cout<<endl;

    cnt=1;
    mp2[b[0]]=1;
    for(i=1;i<n;i++)
    {
        if(b[i]==b[i-1])
        {
            cnt++;
        }
        else
        {
            if(mp2[b[i-1]]<cnt)
            {
                mp2[b[i-1]]=cnt;
                
            }
            cnt=1;
        }
    }

    if(mp2[b[n-1]]<cnt)
            {
                mp2[b[n-1]]=cnt;
                cnt=1;
            }

    // for(auto x:mp2) cout<<x.first<<" --> "<<x.second<<endl;
    // cout<<endl;   

    int maxi=0;
    for(auto ele:mp1)
    {
        maxi=max(ele.second+mp2[ele.first],maxi);
    } 
    for(auto ele:mp2)
    {
        maxi=max(ele.second+mp1[ele.first],maxi);
    }     
   
   cout<<maxi<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}