#include<bits/stdc++.h>
using namespace std;
char s[10005][3][2005],t[3][2005],tmp[2005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,j,k,tl,l,cnt;
	char* tt;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%s %s",s[i][1],s[i][2]);
	while(q--)
	{
		scanf("%s %s",t[1],t[2]);
		tl=strlen(t[1]);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			tt=strstr(t[1],s[i][1]);
			if(tt)
			{
				strcpy(tmp,t[1]);
				l=strlen(s[i][1])+(tt-t[1]);
				for(k=tt-t[1],j=0;k<l;k++,j++)
					tmp[k]=s[i][2][j];
				if(!strcmp(tmp,t[2]))
					cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
