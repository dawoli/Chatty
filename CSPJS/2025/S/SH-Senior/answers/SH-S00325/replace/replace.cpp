#include <bits/stdc++.h>
using namespace std;
#define int long long
string s[200010],t[200010];

template <typename T> void read(T &t)
{
	char c = getchar();
	int f = 1;
	t = 0;
	while(c < '0' || c > '9')
	{
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		t = (t << 3) + (t << 1) + (c ^ 48);
		c = getchar();
	}
	t *= f;
}

bool jud(string a,string b,int pos)
{
	if(pos >= a.length())
		return false;
	if(pos < 0)
		return false;
	if(a[pos] != b[0])
		return false;
	return true;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string now,tar;
	read(n),read(q);
	for(int i = 1; i <= n; i++)
		cin >> s[i] >> t[i];
	while(q--)
	{
		cin >> now >> tar;
		if(now.length() != tar.length())
		{
			cout << 0 << '\n';
			continue;
		}
		int minn = -1,maxn = -1,ans = 0;
		for(int i = 0; i < now.length(); i++)
		{
			if(now[i] != tar[i])
			{
				if(minn == -1)
					minn = i;
				maxn = max(maxn,i);	
			}
		}
		string tarcjh1 = now.substr(minn,maxn - minn + 1),tarcjh2 = tar.substr(minn,maxn - minn + 1);
		for(int i = 1; i <= n; i++)
		{
			int pre = 0;
			while(true)
			{
				int tmp = s[i].find(tarcjh1,pre);
				if(!jud(s[i],tarcjh1,tmp))
					break;
				pre = tmp + 1;
				if(t[i].substr(tmp,maxn - minn + 1) != tarcjh2)
					continue;
				string nows = s[i].substr(0,tmp);
				string nowt = t[i].substr(0,tmp);
				if(nows != nowt)
					break;
				nows += s[i].substr(tmp + maxn - minn + 1);
				nowt += t[i].substr(tmp + maxn - minn + 1);
				if(nows == nowt)
					ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
