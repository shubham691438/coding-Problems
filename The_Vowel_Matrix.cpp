#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      mod        1000000007
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    int n,m;
    cin>>n>>m;

    string str;
    cin>>str;

    int v_cnt=0;
    int gap=0;
    int ans=1;
    for(int i=0;i<n;i++)
    { 
        if(gap>0 && str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u')
        {
            gap++;
        }
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            if(gap)
            {
                ans=((ans%mod)*(gap%mod))%mod;
            }
            v_cnt++;
            if( v_cnt%m==0)
            {
                gap=1;
            }
            else
            {
                gap=0;
            }
        }
              
    }  


    cout<<ans%mod<<endl;
    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}