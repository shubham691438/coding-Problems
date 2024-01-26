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
    for(auto &x:a) {
        cin>>x;
    }

    int firstMis=n;
    for(int i=0;i<n;i++)
        if(a[i] != i)
        {
            firstMis=i;
            break;
        }    

    vector<int> arr=a;
    arr.push_back(firstMis);

    sort(arr.begin(),arr.end());

    int mex=n;
    
    for(int i=0;i<=n;i++)
        if(arr[i] != i)
        {
           mex=i;
           break;
        }   
    // cout<<"MEX "<<mex<<endl;
    // cout<<"firstMis "<<firstMis<<endl;
    cout<<firstMis<<endl<<endl;
    cout<<flush;

    int y;
	cin >> y;
	while (y != -1) {
		cout << y << endl;
        cout<<flush;
        
		cin >> y;
	}
    



}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}