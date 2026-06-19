#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
struct car
{
	int d,v,av;
	int l,r;
	int idl,idr;
	bool ov;
};
car a[100010];
bool p[1000010];
int cnt[1000010];
int lp[1000010];
struct raeg
{
	int l,r;
};
raeg r[100010];
int last=0;
bool cmp(raeg x,raeg y)
{
	if(x.r!=y.r)return x.r<y.r;
	return x.l>y.l;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(cnt,0,sizeof(cnt));
		memset(lp,0,sizeof(lp));
		memset(r,0,sizeof(r));
		last=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].av);
			if(a[i].av==0)
			{
				if(a[i].v<=V)a[i].l=a[i].r=-1;
				else
				{
					a[i].l=a[i].d;
					a[i].r=L;
				}
			}
			else if(a[i].av<0)
			{
				if(a[i].v<=V)
				{
					a[i].l=a[i].r=-1;
				}
				else
				{
					a[i].l=a[i].d;
					int fz=a[i].v*a[i].v-V*V,fm=2*abs(a[i].av);
					if(fz%fm==0)
					{
						a[i].r=a[i].d+fz/fm-1;
					}
					else
					{
						a[i].r=a[i].d+fz/fm;
					}
					if(a[i].r>L)a[i].r=L;
				}
			}
			else
			{
				if(a[i].v>V)
				{
					a[i].l=a[i].d;
					a[i].r=L;
				}
				else
				{
					int fz=V*V-a[i].v*a[i].v,fm=2*a[i].av;
					a[i].l=a[i].d+fz/fm+1;
					if(a[i].l>L)
					{
						a[i].l=a[i].r=-1;
					}
					else
					{
						a[i].r=L;
					}
				}
			}
//			cout<<a[i].l<<' '<<a[i].r<<endl;
		}
		for(int i=1;i<=m;i++)
		{
			int pla;
			scanf("%d",&pla);
			p[pla]=1;
		}
		cnt[0]=p[0];
		if(p[0])lp[0]=1;
		else lp[0]=0;
		for(int i=1;i<=L;i++)
		{
			cnt[i]=cnt[i-1];
			lp[i]=lp[i-1];
			if(p[i])
			{
				cnt[i]++;
				lp[i]=lp[i-1]+1;
			}
		}
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].l!=-1&&a[i].r!=-1&&cnt[a[i].r]-cnt[a[i].l-1]>0)
			{
				ans1++;
				a[i].ov=1;
				if(p[a[i].l]==0)a[i].idl=lp[a[i].l]+1;
				else a[i].idl=lp[a[i].l];
				a[i].idr=lp[a[i].r];
//				cout<<a[i].l<<' '<<a[i].r<<' '<<a[i].idl<<' '<<a[i].idr<<endl;
				last++;
				r[last].l=a[i].idl;
				r[last].r=a[i].idr;
			}
//			cout<<ans1<<endl;
		}
		printf("%d ",ans1);
		if(last==0)
		{
			printf("%d\n",m);
			continue;
		}
		sort(r+1,r+last+1,cmp);
		int ans2=0,mor=-1;
		for(int i=1;i<=last;i++)
		{
			if(mor<r[i].l)
			{
				ans2++;
				mor=r[i].r;
//				cout<<"Q"<<i<<endl;
			}
		}
		printf("%d\n",m-ans2);
	}
	return 0;
}
