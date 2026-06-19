#include <bits/stdc++.h>
using namespace std;
const int N=15000;
const int tbl[21]={-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int t,n;
char s[N];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		if (n<=21) printf("%d\n",tbl[n-1]);
		else
		{
			int k=n/7,h=n%7;
			if (h==0)
			{
				for (int i=0;i<k;++i)
					s[i] = '8';
				s[k] = '\0';
			}
			if (h==1)
			{
				s[0] = '1';
				s[1] = '0';
				for (int i=2;i<=k;++i)
					s[i] = '8';
				s[k+1] = '\0';
			}
			if (h==2)
			{
				s[0] = '1';
				for (int i=1;i<=k;++i)
					s[i] = '8';
				s[k+1] = '\0';
			}
			if (h==3)
			{
				s[0] = '2';
				s[1] = '0';
				s[2] = '0';
				for (int i=3;i<=k;++i)
					s[i] = '8';
				s[k+1] = '\0';
			}
			if (h==4)
			{
				s[0] = '2';
				s[1] = '0';
				for (int i=2;i<=k;++i)
					s[i] = '8';
				s[k+1] = '\0';
			}
			if (h==5)
			{
				s[0] = '2';
				for (int i=1;i<=k;++i)
					s[i] = '8';
				s[k+1] = '\0';
			}
			if (h==6)
			{
				s[0] = '6';
				for (int i=1;i<=k;++i)
					s[i] = '8';
				s[k+1] = '\0';
			}
			printf("%s\n",s);
		}
	}
	return 0;
}
