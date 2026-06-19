#include<bits/stdc++.h>
using namespace std;

//#define for(0,n) for(int lodks=0;lodks<n;lodks++)
#define a1 all_x
#define a2 all_y
#define a3 all_z
//int dsw[100005]={0};!dsw[x.m]
int ck[100005]={0};
struct node
{
	int a1,a2,a3,val,cnt;
};
struct p
{
	int n,m;
};
bool cmp(node x,node y)
{
	int xc=x.a2>x.a3 ? x.a1-x.a2 : x.a1-x.a3;
	int yc=y.a2>y.a3 ? y.a1-y.a2 : y.a1-x.a3;
	return xc>yc || (xc==yc && x.a1>x.a2);
}
bool cmp2(p x,p y)
{
	return !ck[x.m] && x.n>y.n;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ans[t]={0};
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		node a[n];
		p mcn[n];
		for(int j=0;j<100005;j++)
			ck[j]=0;
		for(int l=0;l<n;l++)
		{
			scanf("%d %d %d",&a[l].a1,&a[l].a2,&a[l].a3);
			a[l].val=a[l].a2>a[l].a3 ? a[l].a1-a[l].a2 : a[l].a1-a[l].a3;
			a[l].cnt=a[l].a2-a[l].a3;
		}
		sort(a,a+n,cmp);
		for(int l=0;l<n;l++)
		{
			mcn[l].m=l;
			mcn[l].n=a[l].cnt;
		}
		int j,qwer=0;
		for(j=0;j<n/2;j++)
		{
			if(a[j].val<0)
				break;
			ans[i]+=a[j].a1;
			ck[j]++;
		//	dsw[j]++;
		}
	//	if(a[j].val<0)	j++;
		sort(mcn,mcn+n,cmp2);
		int flag=0;
		for(int k=0;k<n;k++)
		{
			if(qwer>=n/2 || a[mcn[k].m].cnt<0)
				break;
			if(ck[mcn[k].m])
				continue;
			ans[i]+=a[mcn[k].m].a2;
			ck[mcn[k].m]++;
			qwer++;
		}
		for(int k=0;k<n;k++)
		{
			if(!ck[k])
				ans[i]+=a[k].a3;
		}
	}
	for(int i=0;i<t;i++)
		printf("%d\n",ans[i]);
	return 0;
}
