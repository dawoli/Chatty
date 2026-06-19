#include<bits/stdc++.h>
using namespace std;

const int N=100005;
struct Node
{
	int st,ed;
}fst[N];
int d[N],v[N],a[N],p[N];
bool bk[N];
int cnt=0;
bool cmp(Node a,Node b)
{
	if(a.st!=b.st)
		return a.st<b.st;
	return a.ed<b.ed;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,L,V,num,sum;
	int l,r,q;
	double tmp;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&p[i]);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]>V&&p[m]>=d[i])
				{
					for(l=m;l>=1;l--)
						if(p[l]<d[i])
							break;
					++cnt;
					fst[cnt].st=l+1;
					fst[cnt].ed=m;
				}
			}
			else if(a[i]>0)
			{
				tmp=double(V*V-v[i]*v[i])/a[i]/2.0+d[i];
				for(l=m;l>=1;l--)
					if(p[l]<=tmp||p[l]<d[i])
						break;
				if(l<m)
				{
					++cnt;
					fst[cnt].st=l+1;
					fst[cnt].ed=m;
				}
			}
			else if(v[i]>V)
			{
				tmp=double(V*V-v[i]*v[i])/a[i]/2.0+d[i];
				for(l=1;l<=m;l++)
					if(p[l]>=d[i])
						break;
				for(r=l;r<=m;r++)
					if(p[r]>=tmp||p[r]-d[i]<=double(v[i]*v[i])/2.0/a[i])
						break;
				if(l<r)
				{
					++cnt;
					fst[cnt].st=l;
					fst[cnt].ed=r-1;
				}
			}
		}
		cout<<cnt<<' ';
		sort(fst+1,fst+1+cnt,cmp);
		num=0;
		memset(bk,0,sizeof(bk));
		sum=fst[1].ed-fst[1].st+1;
		l=fst[1].ed;
		for(int i=2;i<=cnt;i++)
		{
			if(fst[i].ed<=l)
				continue;
			if(fst[i].st>l)
				sum+=fst[i].ed-fst[i].st+1;
			else
				sum+=fst[i].ed-l;
			l=fst[i].ed;
		}
		for(int i=cnt;i>=1;i--)
		{
			if(bk[i])
				continue;
			q=i-1;
			while(fst[i].ed<=fst[q].ed)
			{
				bk[q]=1;
				q--;
			}
		}
		q=0;
		for(int i=1;i<=cnt;i++)
			if(!bk[i])
			{
				q++;
				fst[q].st=fst[i].st;
				fst[q].ed=fst[i].ed;
			}
		for(int i=1;i<=q;i++)
		{
			num++;
			l=fst[i].ed;
			while(i<q&&fst[i+1].st<=l)
				i++;
		}
		cout<<m-num<<endl;
	}
	return 0;
}
