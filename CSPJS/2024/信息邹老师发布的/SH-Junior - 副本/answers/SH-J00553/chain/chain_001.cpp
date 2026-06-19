#include<bits/stdc++.h>
using namespace std;
int q,t,n,m,l[1001],s[1001][1001]={0},ans=1,c,r,x,y,d,k;
bool map1[1001][1001][1001]={0};
char a;
bool v(int r,int smo,int ri)
{
	if(r==0 && ri==1) return true;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=l[i];j++)
	for(int j1=j;j1<=l[i];j1++)
	{
		if(s[i][j1]==ri && map1[i][j][j1] && i!=smo) return v(r-1,i,s[i][j]);
	}
	return false;
}
int main()
{
    freopen ("chain.in","r",stdin);
    freopen ("chain.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&k,&q);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&l[j]);
			for(int j1=1;j1<=l[j];j1++)
			{
				scanf("%d",&s[j][j1]);
				for(int j2=1;j2<=j1-1;j2++)
				{
					if(j1-j2<k) map1[j][j2][j1]=1;
				}
			}
		}
		for(int j=1;j<=q;j++)
		{
			scanf("%d %d",&r,&c);
			if(v(r,-1,c)) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
