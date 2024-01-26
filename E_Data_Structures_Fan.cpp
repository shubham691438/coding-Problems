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
    ll n;
    cin>>n;
    vector<int> a(n);
    int xor1=0,xor0=0;
    for(int i=0;i<n;i++){
        cin>>a[i];  
    }
        

    string str;
    cin>>str;        

    for(int i=0;i<n;i++)
    {
         if(str[i]=='1')
            xor1=xor1^a[i];
        else
        {
            xor0=xor0^a[i];
        }  
    }

    //calculating prefix xor
    vector<int> preXor(n+1,0);
    preXor[0]=a[0];
    for(int i=1;i<n;i++)
        preXor[i]=preXor[i-1]^a[i];

    // for(int i=0;i<n;i++)
    //     cout<<preXor[i]<<" ";
    // cout<<endl;        

    int q;
    cin>>q;

    while(q--)
    {
        int qtype;
        cin>>qtype;

        if(qtype==1)
        {
            int l,r;
            cin>>l>>r;
            
            //converting to 0 based index
            l--,r--;

            int currXor=preXor[r] ^ ( l-1 >= 0 ? preXor[l-1]:0);

            // cout<<"currXor "<<currXor<<";";
            xor0=xor0^currXor;
            xor1=xor1^currXor;
        }

        else
        {
            int g;
            cin>>g;

            if(g==1) cout<<xor1<<" ";
            else cout<<xor0<<" ";
        }

    }   

    cout<<endl; 


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}