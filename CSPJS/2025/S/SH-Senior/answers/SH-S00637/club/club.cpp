#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,tp[4],a1[50004],a2[50004],a3[50004];
long long ans;
struct club{int x,y,z,c,mx,mp;}a[100005];
bool cmp1(club u,club v)
{
	return u.x>v.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		int cnt1=0,cnt2=0,cnt3=0;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		memset(tp,0,sizeof(tp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x==a[i].mx) a[i].c=a[i].mx-max(a[i].y,a[i].z),a[i].mp=1;
			if(a[i].y==a[i].mx) a[i].c=a[i].mx-max(a[i].x,a[i].z),a[i].mp=2;
			if(a[i].z==a[i].mx) a[i].c=a[i].mx-max(a[i].x,a[i].y),a[i].mp=3;
		}
		bool f=1;
		for(int i=1;i<=n;i++)
			if(a[i].y!=0||a[i].z!=0)
			{
				f=0;
				break;
			}
		if(f)//A
		{
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].mx;
			tp[a[i].mp]++;
			if(a[i].mp==1) cnt1++,a1[cnt1]=a[i].c;
			if(a[i].mp==2) cnt2++,a2[cnt2]=a[i].c;
			if(a[i].mp==3) cnt3++,a3[cnt3]=a[i].c;
		}
//		printf("%lld\n",ans);
		if(tp[1]>n/2)
		{
			sort(a1+1,a1+cnt1+1);
			for(int i=1;i<=tp[1]-n/2;i++) ans-=a1[i];
		}
		if(tp[2]>n/2)
		{
			sort(a2+1,a2+cnt2+1);
			for(int i=1;i<=tp[2]-n/2;i++) ans-=a2[i];
		}
		if(tp[3]>n/2)
		{
			sort(a3+1,a3+cnt3+1);
			for(int i=1;i<=tp[3]-n/2;i++) ans-=a3[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
