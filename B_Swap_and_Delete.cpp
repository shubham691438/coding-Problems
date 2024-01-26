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
  string s;
  cin>>s;

  int cnt1=0,cnt0=0;  
  for(int i=0;i<s.size();i++)
  {
        if(s[i]=='0')
            cnt0++;
        else
            cnt1++;    
  }    

  ll ans=0;  
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='0' && cnt1>0)
    {
       
        cnt1--;
    }
    else if(s[i]=='1' && cnt0>0)
    {
       
        cnt0--;
    }
    else
    {
        ans=s.size()-i;
        break;

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