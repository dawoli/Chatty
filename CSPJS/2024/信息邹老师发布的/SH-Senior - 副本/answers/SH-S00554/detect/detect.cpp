#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p[100005],tr[100005];
void update_tree(int u,int lt,int rt,int x,int v)
{
	if(lt<=rt)
	{
		tr[u]+=v;
		return ;
	}
	int mid=(lt+rt)>>1;
	if(x<=mid)
		update_tree(u<<1,lt,mid,x,v);
	else
		update_tree(u<<1|1,mid+1,rt,x,v);
	tr[u]=tr[u<<1]+tr[u<<1|1];
}
int quary_tree(int u,int lt,int rt,int lc,int rc)
{
	if(lc<=lt&&rt<=rc)
		return tr[u];
	int mid=(lt+rt)>>1;
	if(rc<=mid)
		return quary_tree(u<<1,lt,mid,lc,rc);
	else if(lc>mid)
		return quary_tree(u<<1|1,mid+1,rt,lc,rc);
	else
		return quary_tree(u<<1,lt,mid,lc,mid)+quary_tree(u<<1|1,mid+1,rt,mid+1,rc);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,L,V,i,ans,maxv,flag1,flag2;
	scanf("%d",&t);
	while(t--)
	{
		ans=maxv=flag1=flag2=0;
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(i=1;i<=n;++i)
		{
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
			if(a[i]!=0)
				flag1=1;
			if(a[i]<=0)
				flag2=1;
		}
		for(i=1;i<=m;++i)
			scanf("%d",&p[i]),maxv=max(maxv,p[i]);
		if(!flag1)
		{
			for(i=1;i<=n;++i)
				if(v[i]>V&&d[i]<=maxv)
					++ans;
			printf("%d %d\n",ans,m-1);
		}
		else if(!flag2)
		{
			for(i=1;i<=n;++i)
				if(d[i]<=maxv&&sqrt(v[i]*v[i]+2*a[i]*(maxv-d[i]))>V*1.0)
					++ans;
			printf("%d %d\n",ans,m-1);
		}
		else
		{
			int t,cnt=0;
			for(i=1;i<=m;++i)
				update_tree(1,1,L,p[i],1);
			for(i=1;i<=n;++i)
			{
				t=(V*V-v[i]*v[i])/2*a[i];
				if(a[i]>0)
					if(d[i]+t<=L&&quary_tree(1,1,L,d[i]+t,L))
						++ans;
				else if(a[i]<0)
					if(v[i]>V&&d[i]+t<=L&&quary_tree(1,1,L,d[i],d[i]+t))
					{
						++ans;
						++cnt;
					}
				else
					if(d[i]<=maxv&&v[i]>V)
						++ans;
			}
			printf("%d %d\n",ans,m-1-cnt);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
