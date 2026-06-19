#include <cstdio>
int a[300],b[300];
char str[10];
int cnt[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	a['D']=0;
	a['C']=1;
	a['H']=2;
	a['S']=3;
	b['A']=0;
	b['2']=1;
	b['3']=2;
	b['4']=3;
	b['5']=4;
	b['6']=5;
	b['7']=6;
	b['8']=7;
	b['9']=8;
	b['T']=9;
	b['J']=10;
	b['Q']=11;
	b['K']=12;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		cnt[a[str[0]]*13+b[str[1]]]=1;
	}
	int ans=0;
	for(int i=0;i<52;i++)
	{
		if(cnt[i]==0)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
