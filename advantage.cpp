#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
			cin>>a[i];

		ll l=0,sl=0;
		for(ll i=0;i<n;i++)
		{
			if(a[i]>=l)
			{
				sl=l;
				l=a[i];
			}
			else if(a[i]<l&&a[i]>sl)
				sl=a[i];
		}

		for(ll i=0;i<n;i++)
			if(a[i]!=l)
				cout<<a[i]-l<<" ";
			else
				cout<<l-sl<<" ";

		cout<<endl;	

	}
	return 0;
}