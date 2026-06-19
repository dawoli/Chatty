#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;
string ss[2000010];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
	{
		string a,b;
		cin >> a >>b;
		ss[i] = a;
		mp[a] = b;
	}
	while(q--)
	{
		int ans = 0;
		string t1,t2;
		cin >>t1 >> t2;
		for (int i = 1;i <= n;i++)
		{
			if (ss[i].size() > t1.size()) continue; 
			string s = t1;
			long long x = s.find(ss[i]);
			if (x < s.size())
			{
				s.erase(x,ss[i].size());
				s.insert(x,mp[ss[i]]);
				if (s == t2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
