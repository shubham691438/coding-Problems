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


bool generateParenthesis(int n, int open, int close,
                         string s, string& ans,string str)
{
    // if the count of both open and close parentheses
    // reaches n, it means we have generated a valid
    // parentheses. So, we add the currently generated string
    // s to the final ans and return.
    if (open == n && close == n) {
        if(s.find(str)== string::npos){
            ans=s;
            return true;
        } 
    }
    // At any index i in the generation of the string s, we
    // can put an open parentheses only if its count until
    // that time is less than n.
    if (open < n) {
        if(generateParenthesis(n, open + 1, close, s + "(",ans,str))
        {
            return true;
        }
    }
    // At any index i in the generation of the string s, we
    // can put a closed parentheses only if its count until
    // that time is less than the count of open parentheses.
    if (close < open) {
        if(generateParenthesis(n, open, close + 1, s + ")",ans,str))
        {
            return true;
        }
    }

    return false;
}
 
void solve(){
    string str;
    cin>>str;

    int n=str.size();

    // vector ans is created to store all the possible valid
    // combinations of the parentheses.
    string ans;

    // initially we are passing the counts of open and close
    // as 0, and the string s as an empty string.
    if(generateParenthesis(n, 0, 0, "", ans,str))
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}