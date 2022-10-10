#include<bits/stdc++.h>
using namespace std;

void fn(int n,vector<bool> & prime)
{

	for(int i=2;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(int j=i*i;j<=n;j+=i)
			{
				prime[j]=false;
			}	
		}
	}
}
int main()
{ 
	vector<bool> prime(1e9+1,true);

	prime[1]=false;
	
	int t;
	cin>>t;

	while(t--)
	{
		int x,y;
		cin>>x>>y;
		fn(y,prime);
		for(int i=x;i<=y;i++)
		{
			if(prime[i])
				cout<<i<<endl;
		}
		cout<<endl;
	}
	return 0;
}