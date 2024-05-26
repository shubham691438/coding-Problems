#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>arr,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=ceil(arr[i]*1.0/3);
    }
    return ans;
}
int main()
{
 vector<int>arr={3,2,6};
 cout<<fun(arr,3)<<endl;
}