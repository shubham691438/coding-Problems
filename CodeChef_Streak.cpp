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

    int max1=0,max2=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            cnt1=0;
        }
        else
        {
            cnt1++;
            max1=max(cnt1,max1);
        }

        if(b[i]==0)
        {
            cnt2=0;
        }
        else
        {
            cnt2++;
            max2=max(cnt2,max2);
        }
    } 

    if(max1>max2)
    {
        cout<<"Om"<<endl;
    }   
    else if(max1<max2)
    {
        cout<<"Addy"<<endl;
    }
    else
    cout<<"Draw"<<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}