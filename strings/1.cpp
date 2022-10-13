#include<bits/stdc++.h>
using namespace std;

struct Node{
	struct Node* child[26];
	vector<int> bache; 
};

void insert(struct Node* root,string s,int K,string bad)
{
	
	int n=s.length();

	for(int i=0;i<n;i++)
	{
		struct Node* node=root;
		int k=K;

		for(int j=i;j<n;j++)
		{
		  int curr=s[j]-'a';
		  if((bad[curr]=='0' && k) || (bad[curr]=='1'))
		  {
		  	if(!node->child[curr])
		  {
		  	node->child[curr]=new struct Node;
		  	node->bache.push_back(curr);
		  	// cout<<"adding "<<s[j]<<endl;
		  }
		  node=node->child[curr];
		  if(bad[curr]=='0' ) k--;
		  }

		  else{
		  	break;
		  }

		}

	}
}

int count(struct Node* root)
{
	struct Node* node=root;
	int cnt=0;

		for(auto i:node->bache)
		{
			cnt+=count(node->child[i])+1;
		}
	
	return cnt;
}

int main()
{	

	string s;
	cin>>s;

	string bad;
	cin>>bad;

	int k;
	cin>>k;

	struct Node* root=new struct Node;
	insert(root,s,k,bad);

	cout<<count(root);

	return 0;
}