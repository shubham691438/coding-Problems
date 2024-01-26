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
    ll n,k,x;
    cin>>n>>k>>x;

    if(x!=1)
    {
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i=0;i<n;i++)
            cout<<1<<" ";
        cout<<endl;    
    }
    else if(k==1)
    {
        cout<<"NO"<<endl;
    }

    else if(k==2)
    {
        if(n%2==0)
        {
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++)
                cout<<2<<" ";
            cout<<endl;    
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else 
    {
        
        if(n==1)
        {
            cout<<"NO"<<endl;
        }
        else if(n%2==0)
        {
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++)
                cout<<2<<" ";
            cout<<endl;    
        }
        else if(n==3)
        {
            cout<<"YES"<<endl;
            cout<<1<<endl;
            cout<<3<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
           cout<<1+(n-3)/2<<endl;
           cout<<3<<" ";
           for(int i=0;i<(n-3)/2;i++)
                cout<<2<<" ";

           cout<<endl;     
        }
       
    }    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}