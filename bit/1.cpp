#include<bits/stdc++.h>
using namespace std;


int main()
{
	unsigned long long n,k;
	cin>>n>>k;
	if(k==1)
	{
		cout<< n;
		return 0;
	}	
	unsigned long long res=1;
	while(res<=n)
	{
		res=res<<1;
	}
	cout<<res-1;
	return 0;
}