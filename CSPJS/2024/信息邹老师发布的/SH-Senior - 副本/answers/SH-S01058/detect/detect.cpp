#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100100;
const int M=100100;
const int L=1001000;
struct node
{
	int l,r;
};
node block[N];
int d[N],v[N],a[N];
int p[M];
int left[L],right[L];
int cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,L,V;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
		}
		p[0]=0;p[m+1]=L+1;
		for(int j=1;j<p[1];j++)
		{
			left[j]=0;
		}
		for(int j=p[m]+1;j<=L;j++)
		{
			right[j]=m+1;
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=p[i];j<=p[i+1]-1;j++)
			{
				left[j]=i;
			}
			for(int j=p[i-1]+1;j<=p[i];j++)
			{
				right[j]=i;
			}
		}
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]>V && right[d[i]]<=left[L])
				{
					block[++tot].l=right[d[i]];
					block[tot].r=left[L];
				}
			}
			else if(a[i]>0)
			{
				int s=(V*V-v[i]*v[i]+2*a[i]-1)/(2*a[i]);
				if((V*V-v[i]*v[i])%(2*a[i])==0)
				{
					s++;
				}
				if(s<0) s=0;
				if(d[i]+s<=L && right[d[i]+s]<=left[L])
				{
					block[++tot].l=right[d[i]+s];
					block[tot].r=left[L];
				}
			}
			else
			{
				if(V>v[i]) continue;
				int s=0;
				if(V==v[i])
				{
					s=0;
				}
				else
				{
					s=(int)((V*V-v[i]*v[i])/(2.0*a[i]));
					if((v[i]*v[i]-V*V)%(2*a[i])==0)
					{
						s--;
					}
					if(d[i]+s>L) s=L-d[i];
					if(s>=0 && right[d[i]]<=left[d[i]+s])
					{
						block[++tot].l=right[d[i]];
						block[tot].r=left[d[i]+s];
					}
				}
			}
		}
		sort(block+1,block+1+tot,cmp);
		int last=-1,ans=0;
		for(int i=1;i<=tot;i++)
		{
//			printf("%d %d\n",block[i].l,block[i].r);
			if(last<block[i].l)
			{
				ans++;
				last=block[i].r;
			}
		}
		printf("%d %d\n",tot,m-ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
