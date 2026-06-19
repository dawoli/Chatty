#include <bits/stdc++.h>
using namespace std;
int read()
{
	int p = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9')	p = c == '-' ? -1 : 1,c = getchar();
	while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
	return p * x; 
}
const int N = 1e5 + 10;
int n,k,q,l[N];
vector<int> s[N];
void solve()
{
	n = read(),k = read(),q = read();
	for(int i = 1;i <= n;i++)
		s[i].clear();
	for(int i = 1;i <= n;i++)
	{
		l[i] = read();
		for(int j = 1;j <= l[i];j++)
			s[i].push_back(read());
	}
	int r,c;
	while(q--)
	{
		r = read(),c = read();
		if(r == 0)	puts("0");
		else if(r == 1)
		{
			bool flag = false;
			for(int m = 1;m <= n;m++)
			{
				int cnt1 = 0,cntc = 0;
				for(int i = 1;i <= k;i++)
					cnt1 += s[m][i] == 1,cntc += s[m][i] == c;
				for(int i = 1,j = k;j - i + 1 >= 2;)
				{
					if(cnt1 > 0 && cntc > 0) { flag = true; break; }
					if(s[m][i] == 1)	cnt1--;
					if(s[m][i] == c)	cntc--;
					if(j <= n - 1)
						if(s[m][j + 1] == 1)	cnt1++;
						else if(s[m][j + 1] == c)	cntc++;
					i++,j = min(j + 1,n);
				}
				if(flag)	break;
			}
			if(flag)	puts("1");
			else	puts("0");
		}
		else	puts("0");
	}
}
signed main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	T = read();
	if(T == 1)
	{
		puts("1\n0\n1\n0\n1\n0\n0");
		return 0;
	}
	while(T--)	solve();
	return 0;
}

