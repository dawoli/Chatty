#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char p[55]={'0'};
int main()
{
	//freopen ("poker.in","r",stdin);
	//freopen ("poker.out","w",stdout);
	int n=0,sum=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i-1;j++)
		{
			if (p[i]==p[j])
			{
				p[i]='0';
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (p[i]=='0')
		{
			sum++;
		}
	}
	sum+=52-n;
	cout<<sum<<"\n";
	//fclose (stdin);
	//fclose (stdout);
	return 0;
}
