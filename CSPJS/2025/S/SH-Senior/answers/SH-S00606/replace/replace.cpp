#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
ll n,q,ans;
map<string, string> m;
string a,b,x,v,k;
vector<int> num;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a>>b;
		m[a] = b;
		num.push_back(a.length());
	}
	for(int i = 1 ; i <= q ; i++)
	{
		ans = 0;
		cin>>a>>b;
		if(a == b) ans++;
		x = "";
		for(int i = 0 ; i < a.length()-1 ; i++)
		{
			for(int j = 0 ; j < num.size() ; j++)
			{
				if(j > a.length()-i) break;
				k = a.substr(i,num[j]);
				if(m.find(k) != m.end())
				{
					v = x + m[k] + a.substr(i+num[j],a.length()-i-num[j]);
					if(v == b) ans++;
				}
			}
			x += a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
