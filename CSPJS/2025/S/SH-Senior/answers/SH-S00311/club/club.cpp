#include<bits/stdc++.h>
using namespace std;
short t;
int n,a[100005],b[100005],c[100005],cnt[100005][5];
long long maxn=-1;
bool flag2=true,flag3=true,flag1=true;
void baoli(int step,int ac,int bc,int cc,long long ans)
{
	if(step==0)
	{
		maxn=max(ans,maxn);
		return;
	}
	if(ac>n/2) return;
	if(bc>n/2) return;
	if(cc>n/2) return;
	
	for(int j=1;j<=3;j++)
	{
		if(j==1) baoli(step-1,ac+1,bc,cc,ans+cnt[step][1]);
		if(j==2) baoli(step-1,ac,bc+1,cc,ans+cnt[step][2]);
		if(j==3) baoli(step-1,ac,bc,cc+1,ans+cnt[step][3]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		flag2=true,flag3=true,flag1=true,maxn=-1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) flag2=false;
			if(c[i]!=0) flag3=false;
			if(a[i]!=0) flag1=false;
			cnt[i][1]=a[i],cnt[i][2]=b[i],cnt[i][3]=c[i];
		}
		if((flag2&&flag3))
		{
			sort(a+1,a+n+1);
			long long ans=0;
			for(int i=n;i>n/2;i--) ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		if((flag1&&flag3))
		{
			sort(b+1,b+n+1);
			long long ans=0;
			for(int i=n;i>n/2;i--) ans+=b[i];
			cout<<ans<<endl;
			continue;
		}
		if((flag1&&flag2))
		{
			sort(c+1,c+n+1);
			long long ans=0;
			for(int i=n;i>n/2;i--) ans+=c[i];
			cout<<ans<<endl;
			continue;
		}
		baoli(n,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
