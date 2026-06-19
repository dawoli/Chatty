#include<bits/stdc++.h>
using namespace std;
char sz[10];
int d[100005];
int c[100005];
int h[100005];
int s[100005];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,i,l=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",sz);
		if(sz[0]=='D')
		{
			if(!d[sz[1]])
				l++;
			d[sz[1]]=1;
		}
		if(sz[0]=='C')
		{
			if(!c[sz[1]])
				l++;
			c[sz[1]]=1;
		}
		if(sz[0]=='H')
		{
			if(!h[sz[1]])
				l++;
			h[sz[1]]=1;
		} 
		if(sz[0]=='S')
		{
			if(!s[sz[1]])
				l++;
			s[sz[1]]=1;
		}
	}
	printf("%d",52-l);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
