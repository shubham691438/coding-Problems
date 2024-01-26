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

bool allquestion(string &str)
{
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]!='?')
        {
            return false;
        }
    }

    return true;
}
 
 
void solve(){
    
    string str;
    cin>>str;

    int n=str.size();

    if(allquestion(str))
    {
        for(int i=0;i<n;i++)
            str[i]='1';

        cout<<str<<endl;
        return;    
    }

    //handle start ?
    int i=0;
    while(str[i]=='?')
    {
        i++;
    }

    for(int j=0;j<i;j++)
    {
        str[j]=str[i];
    }  

    // handle end ?
    i=n-1;
    while(str[i]=='?')
    {
        i--;
    }

    for(int j=n-1;j>i;j--)
    {
        str[j]=str[i];
    }    

    for(int i=1;i<n;i++)
    {
        if(str[i]=='?')
        {
            str[i]=str[i-1];
        }
    }

    cout<<str<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}