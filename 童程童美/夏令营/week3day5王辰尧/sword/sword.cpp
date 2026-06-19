#include<iostream>
using namespace std;
int l[105], r[105];
int main()
{
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	int T,a,b;
	cin>>T;
	int maxx=100,minn=0;
	for (int i = 1; i <= T; i++)
	{
		cin>>a>>b;
		l[a]++;r[b]++;
		if (maxx>a)maxx = a;
		if (minn < b)minn = b;
		int m = maxx,n = minn,ma=0;
		int p = l[maxx], q = r[minn];
		int cnt = 0;
		while (cnt != i)
		{
			if (p == 0)
			{
				p = l[++m];
				continue;
			}
			if (q == 0)
			{
				q = r[--n];
				continue;
			}
			if (m + n > ma)ma = m + n;
			if (p == q)
			{
				cnt += p; m++; n--;
				p = l[m]; q = r[n];
			}
			else if (p < q)
			{
				q -= p;
				cnt += p;
				p = l[++m];
			}
			else if (p>q)
			{
				p -= q;
				cnt += q;
				q = r[--n];
			}
		}
		cout<<ma<<endl;
	}
}
