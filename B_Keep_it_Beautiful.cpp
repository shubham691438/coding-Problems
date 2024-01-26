#include <bits/stdc++.h>
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
    vector<int> a(n) ;
    for(auto &x:a) cin>>x;

    vector<int> str(n,0);
    str[0]=1;
    
    int i=1;
    while(a[i]>=a[i-1])
    {
        str[i]=1;
        i++;
    }

    //finding the first element which is less than or equal to a[0]
    int pos=n;
    for(int j=i;i<n;j++)
    {
        if(a[j]<=a[0])
        {
            pos=j;
        }
    }

    int j,last=a[pos];
    for(j=pos;j<n;j++)
    {
        if(a[j]>=last && a[0]>=a[j] && a[j]>=a[pos])
        {
            str[j]=1;
            last=a[j];
        }
    }

    for(int i=0;i<n;i++)
        cout<<str[i];

   cout<<endl;     
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}