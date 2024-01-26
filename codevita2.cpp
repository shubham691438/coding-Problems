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

 int findMinJars(vector<int> A,int C,int K,int N){
    sort(A.begin(),A.end());

    ll ans=0,cnt=1;
    set<int> st;
    for(int i=1;i<N;i++)
    {
      
        if( (A[i]-*st.begin()) > K || cnt>=C)
        {
            st.clear();
            
            ans++;
            cnt=1;
        }
        else
        {
            st.insert(A[i]);
            cnt++;
        }
    }

    return ans+1;
 }
 
void solve(){
    ll n,c,k;
    cin>>n>>c>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<findMinJars(a,c,k,n)<<endl;
   
    


}
 
 
int main(){
    fastio
    // w(t){
        solve();
    // }
}