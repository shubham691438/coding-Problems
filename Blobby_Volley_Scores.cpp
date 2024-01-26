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

    map<char,int> mp;
    char t='A';
    for(int i=0;i<n;i++)
    {
        if(t==str[i])
        {
            mp[str[i]]++;
        }
        else
        {
            if(t=='A')
            {
                t='B';
            }
            else
            {
                t='A';
            }
        }
    }  

    cout<<mp['A']<<" "<<mp['B']<<endl;  
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}