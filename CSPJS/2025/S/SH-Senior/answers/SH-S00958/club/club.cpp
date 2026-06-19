#include<bits/stdc++.h>
using namespace std;

int n,t;
long long a[100005][3];
long long A[100005];
long long ans;
bool fA=1,fB=1;
bool flag[100005];

struct B
{
	int id;
	long long sub;
}b[100005];

bool cmp(B x,B y)
{
	return x.sub>y.sub;
}

void BFdfs(int nowid,long long nowans,int choose,int now1,int now2,int now3)
{
	if(now1>n/2||now2>n/2||now3>n/2)return;
	if(nowid==n)
	{
		ans=max(ans,nowans);
		return;
	}
	BFdfs(nowid+1,nowans+a[nowid+1][0],0,now1+1,now2,now3);
	BFdfs(nowid+1,nowans+a[nowid+1][1],1,now1,now2+1,now3);
	BFdfs(nowid+1,nowans+a[nowid+1][2],2,now1,now2,now3+1);
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			if((a[i][1]!=0||a[i][2]!=0)&&fA)fA=0;
			if(a[i][2]!=0&&fB)fB=0;
		}
		if(n<=10)
		{
			BFdfs(1,a[1][0],0,1,0,0);
			BFdfs(1,a[1][1],1,0,1,0);
			BFdfs(1,a[1][2],2,0,0,1);
			printf("%lld",ans);
		}
		else if(fA)
		{
			for(int i=1;i<=n;i++)
			{
				A[i]=a[i][0];
			}
			sort(A+1,A+1+n);
			for(int i=1;i<=n/2;i++)
			{
				ans+=A[i];
			}
			printf("%lld",ans);
		}
		else if(fB)
		{
			for(int i=1;i<=n;i++)
			{
				b[i].id=i;
				b[i].sub=a[i][0]-a[i][1];
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				flag[b[i].id]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(flag[i])ans+=a[i][0];
				else ans+=a[i][1]; 
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
