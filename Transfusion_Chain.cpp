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

    vector<string> strs(n);
    for(int i=0;i<n;i++)
        cin>>strs[i];

    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(strs[i-1]=="A")
        {
            if(strs[i]=="A" || strs[i]=="AB")
                cnt++;
        }
        else if(strs[i-1]=="B")
        {
            if(strs[i]=="B" || strs[i]=="AB")
                cnt++;
        }
        else if(strs[i-1]=="AB")
        {
            if(strs[i]=="AB")
                cnt++;
        }
        else
        {
            if(strs[i]=="A" ||strs[i]=="B" ||strs[i]=="AB")
                cnt++;
        }
    } 

    //comparing last with the first
    if(strs[n-1]=="A")
        {
            if(strs[0]=="A" || strs[0]=="AB")
                cnt++;
        }
        else if(strs[n-1]=="B")
        {
            if(strs[0]=="B" || strs[0]=="AB")
                cnt++;
        }
        else if(strs[n-1]=="AB")
        {
            if(strs[0]=="AB")
                cnt++;
        }
        else
        {
            if(strs[0]=="A" ||strs[0]=="B" ||strs[0]=="AB")
                cnt++;
        }    

    cout<<cnt<<endl;   
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}