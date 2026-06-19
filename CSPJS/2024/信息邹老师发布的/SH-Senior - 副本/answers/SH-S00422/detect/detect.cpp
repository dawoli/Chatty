#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int N=2e5+10,M=1e6+10;
struct node
{
	long long d,v,a;
}c[N];
struct node2
{
	long long l,first,second;
	friend bool operator<(node2 A,node2 B)
	{
		if(A.first==B.first && A.second==B.second)
			return A.l<B.l;
		if(A.first==B.first)
			return A.second<B.second;
		return A.first<B.first;
	}
};
int p[N];
long long sum[M];
node2 cars[2*N];
long long n,m,L,V;

bool get(long long l,long long r)
{
	if(r<l)
		return false;
	if(r>L)
		r=L;
	if(l==0)
		return sum[r]>0;
	return (sum[r]-sum[l-1])>0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(sum,0,sizeof(sum));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
			sum[p[i]]++;
		}
		for(int i=1;i<=L;i++)
			sum[i]+=sum[i-1];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i].a>0)
			{
				long long broad=c[i].d+(V*V-c[i].v*c[i].v)/(2*c[i].a)+1;
				if(broad>L)
					continue;
				if(get(broad,L))
					cars[cnt++]={broad,L,1};
			}
			else if(c[i].a==0)
			{
				if(c[i].v>V && get(c[i].d,L))
					cars[cnt++]={c[i].d,L,1};
			}
			else
			{
				if(c[i].v<=V)
					continue;
				long long broad=c[i].d+(c[i].v*c[i].v-V*V)/(-2*c[i].a);
				if((c[i].v*c[i].v-V*V)%(-2*c[i].a)==0)
					broad--;
				if(get(c[i].d,broad))
					cars[cnt++]={c[i].d,broad,1};
			}
		}
		for(int i=1;i<=m;i++)
			cars[cnt+i-1]={0,p[i],0};
		sort(cars,cars+cnt+m);
		int last=-1,num=0,res=0,tmp=-1;
		for(int i=0;i<cnt+m;i++)
		{
			if(cars[i].second==1)
			{
				if(cars[i].l<=last)
					continue;
				res+=num-1;
				num=0;
				last=tmp;
			}
			else
			{
				tmp=cars[i].first;
				num++;
			}
		}
		res+=num;
		cout<<cnt<<" "<<res<<endl;
	}
    return 0;
}
