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

		int eq=1;
		for(ll i=0;i<n;i++)
			if(a[i]!=a[0])
				eq=0;

		if(eq==0)
		{
					//removing duplicates
				vector <ll> u;

				for(ll i=1;i<n;i++)
					if(a[i]==a[i-1])
					{
						a[i-1]=0;
					}

				for(ll i=0;i<n;i++)
					if(a[i])
					{
						u.push_back(a[i]);
					}	



				int f=0;
				//front
				if(u[1]>u[0])
					f++;

				//end
				if(u[u.size()-2]>u[u.size()-1])
					f++;

				//inbetween
				for(ll i=1;i<u.size()-1;i++)
				{
					if(u[i]<u[i-1] && u[i]<u[i+1])
						f++;
				}

				
				if(f==1)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
		}	

		else
		 cout<<"YES"<<endl;
		
	}
	return 0;
}