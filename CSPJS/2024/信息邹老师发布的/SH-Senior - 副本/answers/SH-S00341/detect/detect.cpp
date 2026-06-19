#include<bits/stdc++.h>
using namespace std;

int i,T,n,m,L,V,pos,res,tmp,p[100001];
struct Car
{
	int d;
	int v;
	int a;
	bool oversp = 0;
}c[100001];
bool cmp(Car x,Car y){return (x.oversp>y.oversp?1:(x.a>y.a));}
int fd(int n,int l,int r)
{
	if(l >= r)return l;
	int mid = (l+r)/2;
	if(n == p[mid])return mid;
	if(n < p[mid])return fd(n,l,mid-1);
	if(n > p[mid])return fd(n,mid+1,r);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		res = 0;
		scanf(" %d %d %d %d",&n,&m,&L,&V);
		for(i = 0;i < n;i++)scanf(" %d %d %d",&c[i].d,&c[i].v,&c[i].a);
		for(i = 0;i < m;i++)scanf(" %d",&p[i]);
		for(i = 0;i < n;i++)
		{
			if(c[i].d > p[m-1])continue;
			if(c[i].a >= 0)
			{
				if((long long)c[i].v*(long long)c[i].v + 2*(long long)c[i].a*(long long)(p[m-1]-c[i].d) > (long long)(V*V))
				{
					res++;
					c[i].oversp = 1;
				}
			}
			else
			{
				if(c[i].d <= p[0])pos = 0;
				else
				{
					tmp = fd(c[i].d,0,m-1);
					pos = c[i].d <= p[tmp]?tmp:tmp+1;
				}
				if((long long)c[i].v*(long long)c[i].v + 2*(long long)c[i].a*(long long)(p[pos]-c[i].d) > (long long)(V*V))
				{
					res++;
					c[i].oversp = 1;
				}
			}
		}
		cout<<res<<' ';
		if(res == 0)
		{
			cout<<m<<endl;
			continue;
		}
		sort(c,c+n,cmp);
		if((c[0].a == 0 && c[res-1].a == 0) || c[res-1].a > 0)
		{
			cout<<m-1<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
