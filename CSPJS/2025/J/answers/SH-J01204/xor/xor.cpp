#include <bits/stdc++.h>
using namespace std;
long long n,k,maxx,num;
vector <int> v[500005];
int check(int m,int p)
{
	int w=1;
	long long sum=0,l=1;
	while(1)
	{
		if(m%2!=p%2)
		{
			for(int i=1;i<=w-1;i++)
				l*=2;
			sum+=l;
			l=1;
		}
		m/=2;
		p/=2;
		w+=1;
		if(m==0 && p==0)
			return sum;
	}
}
int dp(int k)
{
	for(int i=k;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(v[i][j]==3)
			{
				num++;
				if(maxx<num)
					maxx=num;
				dp(j+1);
				num--;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int a[n+5];
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
				v[i].push_back(a[i]);
			else
				v[i].push_back(check(a[j-1],a[j]));
		}
	}
	num=dp(1);
	cout << maxx;
	return 0;
}
