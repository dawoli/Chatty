#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int d;
	bool operator < (const struct node &t) const
	{
		return d>t.d;
	}
} NODE,*PNODE;
NODE x[100005],y[100005],z[100005];
int cnt[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(a>=b&&a>=c)
			{
				x[++cnt[0]].d=min(a-b,a-c);
				ans+=a;
			}
			else if(b>a&&b>=c)
			{
				y[++cnt[1]].d=min(b-a,b-c);
				ans+=b;
			}
			else if(c>a&&c>b)
			{
				z[++cnt[2]].d=min(c-a,c-b);
				ans+=c;
			}
		}
		if(cnt[0]>n/2)
		{
			sort(x+1,x+cnt[0]+1);
			while(cnt[0]>n/2)
				ans-=x[cnt[0]--].d;
		}
		else if(cnt[1]>n/2)
		{
			sort(y+1,y+cnt[1]+1);
			while(cnt[1]>n/2)
				ans-=y[cnt[1]--].d;
		}
		else if(cnt[2]>n/2)
		{
			sort(z+1,z+cnt[2]+1);
			while(cnt[2]>n/2)
				ans-=z[cnt[2]--].d;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
