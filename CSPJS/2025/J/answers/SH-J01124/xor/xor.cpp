#include <cstdio>
const int N=500100;
int a[N],pre[N];
int tong[1100000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	pre[1]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i+1]=pre[i]^a[i];
	}
	//pre_length : n+1 !!!!!!!
	int last=0,cnt=0;
	for(int i=1;i<=n+1;i++)
	{
		if(tong[pre[i]^k]!=0)
		{
			if(last<=tong[pre[i]^k])
			{
				last=i;
				cnt++;
			}
		}
		tong[pre[i]]=i;
	}
	printf("%d\n",cnt);
	fclose(stdin);fclose(stdout);
	return 0;
}
