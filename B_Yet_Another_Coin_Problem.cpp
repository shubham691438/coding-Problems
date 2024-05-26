#include<bits/stdc++.h>
 
using namespace std;
 
int getAns(int n){

    if(n<0) return 1e9+7;

    int ans=0;
    ans+=n/15;
    n%=15;
    ans+=n/6;
    n%=6;
    ans+=n/3;
    n%=3;
    ans+=n;
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int testcases;
    cin>>testcases;
    for(int i=1;i<=testcases;i++){
        int n;cin>>n;
        
    //at max 2 tens can be used 
    cout<<min({getAns(n),getAns(n-10)+1,getAns(n-20)+2})<<endl;
     
    }
}