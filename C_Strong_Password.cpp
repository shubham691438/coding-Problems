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
    string str;
    cin>>str;

    ll n=str.size();

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        a[i]=str[i]-'0';
        // cout<<a[i]<<" ";
    }
    // cout<<endl;

    ll m;
    cin>>m;

    string  l,r;
    cin>>l>>r;

    bool ans=0;
    int start=0,tempStart=0;
    int maxi=INT_MIN;
    for(int i=0;i<m;i++)
    {
        for(int j=l[i]-'0';j<=r[i]-'0';j++)
        {
            // cout<<j<<" -> ";
            tempStart=start;
            if( tempStart<n && find(a.begin()+tempStart,a.end(),j)!= a.end())
            {
                tempStart=find(a.begin()+tempStart,a.end(),j)-a.begin();
                maxi=max(maxi,tempStart);
                // cout<<tempStart<<" ";
            }
            else
            {
                ans=true;
                break;
            }
            // cout<<endl;          
            
        }
        start=maxi+1;
        
    }
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}