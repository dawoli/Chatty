#include<bits/stdc++.h>
using namespace std;
int v,n,k,q,s[1001][100001],r,c,l[100001],t[200001];
bool ch(int r,int c,int f,int b)
{
	if(r == 0) return (f == c);
	for(int i = 1 ; i <= n ; i++)
	{
		if(i != b)
		{ 
			for(int j = 1 ; j <= l[i] ; j++)
			{
				if(s[i][j] == f)
				{
					for(int y = 1 ; y < k ; y++)
					{
						if(ch(r-1,c,s[i][j+y],i)) return true;
					}
				}
			}
		}
	}
	return false; 
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&v);
	while(v--)
	{
		scanf("%d%d%d",&n,&k,&q);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d",&l[i]);
			for(int j = 1 ; j <= l[i] ; j++)
			{
				scanf("%d",&s[i][j]);
				t[s[i][j]] = 1;
			}
		}
		for(int i = 1 ; i <= q ; i++)
		{
			scanf("%d%d",&r,&c);
			if(!t[1] || !t[c])
			{
				printf("0\n");
				continue;
			}
			if(ch(r,c,1,0)) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
