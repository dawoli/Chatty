#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t,cnt[4],ans,b[100005],cntb;
struct node
{
	int x[4],maxid;
	bool flag;
	void f()
	{
		maxid=max_element(x+1,x+4)-x;
		cnt[maxid]++;
		ans+=*max_element(x+1,x+4);
		nth_element(x+1,x+2,x+4);
		x[2]=x[1]-x[2];
		x[3]=0;
	}
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=cnt[1]=cnt[2]=cnt[3]=cntb=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)scanf("%d",&a[i].x[j]);
			a[i].f();
		}
		int tmp=*max_element(cnt+1,cnt+4),id=max_element(cnt+1,cnt+4)-cnt;
		if(tmp<=n/2)
		{
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].maxid==id)
			{
				b[++cntb]=a[i].x[2];
			}
		}
		nth_element(b+1,b+tmp-n/2+1,b+tmp+1);
		for(int i=1;i<=tmp-n/2;i++)
		{
			ans-=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

