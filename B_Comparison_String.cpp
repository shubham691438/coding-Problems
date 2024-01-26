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
    string str;
    cin>>str;

    int cntg=0,cntl=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='<')
        {
            cntg++;
            maxi=max(cntg,maxi);
        }
        else
        {
            maxi=max(cntg,maxi);
            cntg=0;
        }

        if(str[i]=='>')
        {
            cntl++;
            maxi=max(cntl,maxi);
        }
        else
        {
            maxi=max(cntl,maxi);
            cntl=0;
        }

        
    }    


    cout<<1+maxi<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}