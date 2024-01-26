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
        cin >> n;
        int max = 2 * n;
        int min = 2;
        

        // for first line
        for (int i = 0; i < n;)
        {
            if (i < n)
            {
                cout << max << " ";
                max -= 2;
                i++;
            }
            if (i < n)
            {
                cout << min << " ";
                min += 2;
                i++;
            }
        }
        cout << endl;
        max = (2 * n) - 1;
        min = 1;

        //for second line 
        for (int i = 0; i < n;)
        {
            if (i < n)
            {
                cout << min << " ";
                min += 2;
                i++;
 
            }
            if(i==1){
                cout<<n+1<<" ";
                i++;
                max-=2;
                continue;
            }
            if(i==n-1){
                cout<<2*n-1;
                i++;
                max-=2;
                continue;
            }
            if (i < n)
            {
                cout << max << " ";
                max -= 2;
                i++;
            }
        }
        cout << endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}