#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		if (n%8==0)
		{
			int x=n/8;
			for (int j=1;j<=x;j++)
			{
				printf("8");
			}
			printf("\n");
		}
		if (n%8==1) printf("-1\n");
	}
}
