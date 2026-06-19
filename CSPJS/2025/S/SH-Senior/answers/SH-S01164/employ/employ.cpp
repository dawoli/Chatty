#include<bits/stdc++.h>
using namespace std;
int a[505];
int e[505];
int p[505];
int n;
int dfs(int l)
{
	if(l==n)
		return 1;
	int i,s=0;
	for(i=0;i<=n;++i)
	{
		if(!p[i]) continue;
		p[i]--;
		s+=dfs(l+1);
		p[i]++;
	}
	return s;
}
int main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int i,j,m,f=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%1d",&a[i]);
		if(a[i]==0)
			f=1;
	}
	if(!f)
	{
		for(i=1;i<=n;++i)
		{
			scanf("%d",&f);
			p[f]++;
		}
		printf("%d\n",dfs(0));
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
