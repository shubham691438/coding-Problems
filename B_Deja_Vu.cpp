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

vector<int> getUniqueWithOrder(const vector<int>& input) {
    vector<int> uniqueElements;
    for (int element : input) {
        if (find(uniqueElements.begin(), uniqueElements.end(), element) == uniqueElements.end()) {
            uniqueElements.push_back(element);
        }
    }
    return uniqueElements;
} 
 
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n),b(q);
    for(auto &x:a ) cin>>x;    
    for(auto &x:b ) cin>>x; 

    vector<int> u=getUniqueWithOrder(b);

    for(int i=0;i<u.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            if( a[j]% (1<<u[i]) ==0 )
            {
                a[j]= a[j]+ (1<<(u[i]-1));
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}