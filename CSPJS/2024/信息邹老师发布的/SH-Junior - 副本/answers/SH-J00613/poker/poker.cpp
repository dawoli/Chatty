#include<bits/stdc++.h>
using namespace std;
char a[3][53];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,sum=0;
	cin>>n;
	sum=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=2;j++)
			cin>>a[j][i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[1][i]==a[1][j]&&a[2][i]==a[2][j])
			{
				sum--;
			}
		}
	}
	cout<<52-sum;
	return 0;
}
