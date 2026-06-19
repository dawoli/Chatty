#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	bool flag=false;
	cin>>n;
	string a[53];
	string a1[53];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a1[i]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			if (a[i]==a1[j])
			{
				flag=true;
			}
		}
		if (flag==false)
		{
			cnt++;
		}
		flag=false;
	}
	cout<<52-cnt;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
