#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;

		int arr[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=s[i]-'a';
		}
		int l=arr[0];
		for(int i=0;i<n;i++)
			if(arr[i]>l)
				l=arr[i];

		cout<<l+1<<endl;		

	}
	return 0;
}