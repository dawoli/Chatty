#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,k;
	char a[53],b[53];
	cin>>n;
	k=n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]==a[j]&&b[i]==b[j]&&a[i]!='0')
			{
				a[j]='0',b[j]='0';
				k--;
			}
	cout<<52-k;
	return 0;
}
