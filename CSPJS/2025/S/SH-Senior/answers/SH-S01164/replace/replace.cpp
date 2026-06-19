#include<bits/stdc++.h>
using namespace std;
char q1[10005][10005],q2[10005][10005];
char c1[200005],c2[200005];
char s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int l1,l2,ans=0;
	int i,j,k;
	int n,m;
	scanf("%d %d\n",&n,&m);
	for(i=1;i<=n;++i)
	{
		gets(s);
		j=0;
		while(s[j]!=' ')
		{
			q1[i][j]=s[j];++j;
		}
		for(k=0;k<j;++k)
			q2[i][k]=s[j+k+1];
	}
	while(m--)
	{
		ans=0;
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		gets(s);
		j=0;
		while(s[j]!=' ')
		{
			c1[j]=s[j];++j;
		}
		for(k=0;s[j+k+1];++k)
			c2[k]=s[j+k+1];
		l1=strlen(c1);
		if(l1!=strlen(c2))
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<l1;++i)
		{
			for(j=1;j<=n;++j)
			{
				l2=strlen(q1[j]);
				for(k=0;k<l2;++k)
					if(q1[j][k]!=c1[k+i]||c2[k+i]!=q2[j][k])
						break;
				if(k!=l2)
					continue;
				for(k=l2+i;k<l1;++k)
					if(c1[k]!=c2[k])
						break;
				if(k==l1&&c1[k-1]==c2[k-1])
					++ans;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
