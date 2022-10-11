#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;

	stack<char> ss;
	for(auto cu:s)
	{
		if(ss.empty())
		{
			ss.push(cu);
			continue;
		}
		else{
			char curr=ss.top();
			if(curr==cu)
				ss.pop();
			else
				ss.push(cu);
		}
	}

	if(ss.empty())
		cout<<"YES";
	else cout <<"NO";
	return 0;
}