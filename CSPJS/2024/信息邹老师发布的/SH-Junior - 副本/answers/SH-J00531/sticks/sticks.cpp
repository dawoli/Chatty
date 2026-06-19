#include <bits/stdc++.h>
using namespace std;
int f[20];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	f[0]=f[1]=-1;
	f[2]=1;
	f[3]=7;
	f[4]=4;
	f[5]=2;
	f[6]=6;
	f[7]=8;
	f[8]=10;
	f[9]=18;
	f[10]=22;
	f[11]=20;
	f[12]=28;
	f[13]=68;
	f[14]=88;
	
	while(T--)
	{
		scanf("%d",&n);
		if(n<15)
		{
			printf("%d\n",f[n]);
			continue;
		}
		int t=(n/7-1);
		printf("%d",f[n-t*7]);
		for(int i=1;i<=t;i++) printf("8");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
