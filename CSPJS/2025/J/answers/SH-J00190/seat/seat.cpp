#include<bits/stdc++.h>
using namespace std;
int arr[105],st[15][15],vis[15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,x=1,y=1,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n*m;++i)
		scanf("%d",&arr[i]);
	k=arr[1];
	sort(arr+1,arr+n*m+1);
	for(i=1;i<=n*m;++i)
	{
		st[x][y]=arr[n*m-i+1];
		if(y%2)
		{
			if(x==n)
				++y;
			else
				++x;
		}
		else
		{
			if(x==1)
				++y;
			else
				--x;
		}
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(st[i][j]==k)
				printf("%d %d",j,i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
