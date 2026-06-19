#include<bits/stdc++.h>
using namespace std;
typedef struct student
{
	int x,y,z;
	bool operator < (const struct student &t)const
	{
		return x>t.x;
	}
}NODE;
NODE a[100005];
int ansBL,u[100005],v[100005],w[100005];
void solveA(int n)
{
	int ans=0,i;
	sort(a+1,a+1+n);
	n>>=1;
	for(i=1;i<=n;i++)
		ans+=a[i].x;
	printf("%d\n",ans);
	return;
}
void solveB(int n)
{
	int ans=0,i;
	for(i=1;i<=n;i++)
	{
		a[i].z=a[i].x;
		a[i].x-=a[i].y;
	}
	sort(a+1,a+1+n);
	for(i=n>>1+1;i<=n;i++)
		ans+=a[i].y;
	n>>=1;
	for(i=1;i<=n;i++)
		ans+=a[i].x;
	printf("%d\n",ans);
	return;
}
void solveBL(int n,int index,int cnt,int al,int bl,int cl)
{
	if(index==n+1)
	{
		ansBL=max(ansBL,cnt);
		return;
	}
	if(al<n>>1)
		solveBL(n,index+1,cnt+a[index].x,al+1,bl,cl);
	if(bl<n>>1)
		solveBL(n,index+1,cnt+a[index].y,al,bl+1,cl);
	if(cl<n>>1)
		solveBL(n,index+1,cnt+a[index].z,al,bl,cl+1);
}
void solveALL(int n)
{
	int ans=0,i,ut,vt,wt,t;
	for(i=1;i<=n;i++)
		u[i]=v[i]=w[i]=0;
	for(i=1;i<=n;i++)
	{
		ut=a[i].x-max(a[i].y,a[i].z);
		vt=a[i].y-max(a[i].x,a[i].z);
		wt=a[i].z-max(a[i].y,a[i].x);
		if(ut>=vt&&ut>=wt)
			u[i]=ut;
		else if(vt>=ut&&vt>=wt)
			v[i]=vt;
		else if(wt>=ut&&wt>=vt)
			w[i]=wt;
	}
	sort(u+1,u+1+n);
	sort(v+1,v+1+n);
	sort(w+1,w+1+n);
	t=n>>1;
	ut=vt=wt=0;
	for(i=1;i<=t;i++)
	{
		ut+=u[i];
		vt+=v[i];
		wt+=w[i];
	}
	t>>=1;
	if(ut>=vt&&ut>=wt)
	{
		vt=wt=0;
		for(i=1;i<=t;i++)
		{
			vt+=v[i];
			wt+=w[i];
		}
	}
	else if(vt>=ut&&vt>=wt)
	{
		ut=wt=0;
		for(i=1;i<=t;i++)
		{
			ut+=u[i];
			wt+=w[i];
		}
	}
	else if(wt>=ut&&wt>=vt)
	{
		vt=ut=0;
		for(i=1;i<=t;i++)
		{
			vt+=v[i];
			ut+=u[i];
		}
	}
	printf("%d\n",ut+vt+wt);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i;
	bool flag1=1,flag2=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			if(flag1&&(a[i].y||a[i].z))
				flag1=0;
			if(flag2&&a[i].z)
				flag2=0;
		}
		if(flag1)
			solveA(n);
		else if(flag2)
			solveB(n);
		else if(n<=10)
		{
			ansBL=0;
			solveBL(n,1,0,0,0,0);
			printf("%d\n",ansBL);
		}
		else
			solveALL(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
