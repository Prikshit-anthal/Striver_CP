#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define mci map<char,int>
#define pb push_back
#define mp make_pair
#define M 1101
#define MOD 1000000007
#define fi first
#define se second
#define vi vector<int>
#define vl vector<ll>
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define repl(i,l,r) for(long long i=l;i<=r;++i)
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define repd(i,l,r) for (int i=r;i>=l;i--)
#define ins insert
#define inf 10000000000000000ll
#define vpi vector< pair<int,int> >
#define vpl vector< pair<ll,ll> >
#define eps 1e-7
 
#define endl "\n"
/*ll gcd(ll a,ll b){if(a==0){return b;}return gcd(b%a,a);}*/
ll modexp(ll x, ll y, ll p)
{
	ll res = 1; x %= p; while (y) { if (y & 1) { res = (res * x) % p; }y = y >> 1; x = (x * x) % p; }return res;
}
/*int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; */
const int maxn = 2e3 + 10;
const int p = 13331;
const int p1 = 7919;
const int m = 1e9 + 9;
int pre[maxn];
int main()
{
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	set<int>bad;
	string x;
	cin >> x;
	for (int i = 0; i < 26; i++)
	{
		if (x[i] == '0')
		{
			bad.insert(i + 1);
		}
	}
	int k;
	cin >> k;
	int n = s.length();
	pre[0] = 0;
	rep(i, 0, n - 1)
	{
		int y = 0;
		int z = s[i] - 'a' + 1;
		if (bad.find(z) != bad.end())
		{
			y = 1;
		}
		pre[i + 1] = pre[i] + y;
	}
	vector<long long> p_pow(n);
	vector<long long> p1_pow(n);
	p_pow[0] = 1;
	for (int i = 1; i < n; i++)
	{
		p_pow[i] = (p_pow[i - 1] * p) % m;
	}
	p1_pow[0] = 1;
	for (int i = 1; i < n; i++)
	{
		p1_pow[i] = (p1_pow[i - 1] * p1) % m;
	}
	vector<ll>inv(n, 1);
	vector<ll>inv1(n, 1);
	rep(i, 1, n - 1)
	{
		inv[i] = modexp(p_pow[i], m - 2, m);
		inv1[i] = modexp(p1_pow[i], m - 2, m);
	}
	vector<long long> h(n + 1, 0);
	vector<long long>h1(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
		h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * p1_pow[i]) % m;
	}
	set<pair<ll,ll>>ans;
	int c = 0;
	//vector<pair<int, int>>vp;
	rep(i, 0, n - 1)
	{
		rep(j, i, n - 1)
		{
			if ((pre[j + 1] - pre[i]) <= k)
			{
				ll curr = (h[j + 1] + m - h[i]) % m;
				curr = (curr * inv[i]) % m;
				ll curr1 = (h1[j + 1] + m - h1[i]) % m;
				curr1 = (curr1 * inv1[i]) % m;
				pair<ll, ll> pt = make_pair(curr, curr1);
				if (ans.find(pt) == ans.end())
				{
					//vp.pb({ i,j });
					ans.insert(pt);
					c++;
				}
			}
		}
	}
	cout << c << "\n";
 
 
 
 
 
 
	return 0;
 
	/*check for long long or int*/
}