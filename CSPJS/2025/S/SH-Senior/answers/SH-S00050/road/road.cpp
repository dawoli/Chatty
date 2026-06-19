#include<bits/stdc++.h>
using namespace std;
const int K=12;
const int N=1e4+100;
const int M=1e6+100; 
int q[K];
array<int,3>kedges[K][N],edges[M];
int fa[N+K];
int daibiao(int in)
{
	return in==fa[in]?in:fa[in]=daibiao(fa[in]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edges[i]={c,a,b};
	}
	sort(edges,edges+m);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&q[i]);
		for(int j=0;j<n;j++)
		{
			int t;
			scanf("%d",&t);
			kedges[i][j]={t,i+n,j+1};
		}
		sort(kedges[i],kedges[i]+n);
	}
	long long minans=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		vector<int>l;
		int h[K]={0,0,0,0,0,0,0,0,0,0,0};
		long long nans=0;
		for(int j=0;j<k;j++)
		{
			if((1<<j)&i)
			{
				nans+=q[j+1];
				l.push_back(j+1);
			}
		}
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int cnt=n+l.size();
		//cout<<i<<endl;
		//cout<<"this is l"<<endl;
		//for(auto y:l)cout<<y<<endl;
		//cout<<endl;
		//cout<<"nn="<<nn<<endl; 
		while(cnt>1 && nans<minans)
		{
			//cout<<cnt<<" & "<<nans<<endl;
			int nc=-1;
			array<int,3>t={int(1e9+10),0,0};
			while(h[0]<m)
			{
				int u=edges[h[0]][1],v=edges[h[0]][2];
				if(daibiao(u)==daibiao(v))h[0]++;
				else break;
			}
			if(h[0]<m && edges[h[0]]<t)
			{
				nc=0;
				t=edges[h[0]];
			}
			for(auto y:l)
			{
				//cout<<"%%"<<endl;
				if(h[y]==n)continue;
				while(h[y]<n)
				{
					int u=kedges[y][h[y]][1],v=kedges[y][h[y]][2];
					if(daibiao(u)==daibiao(v))h[y]++;
					else break;
				}
				if(h[y]==n)continue;
				if(kedges[y][h[y]]<t)
				{
					nc=y;
					t=kedges[y][h[y]];
				}
			}
			//cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<endl;
			h[nc]++;
			fa[daibiao(t[1])]=daibiao(t[2]);
			nans+=t[0];
			cnt--;
		}
		//cout<<nans<<endl;
		minans=min(minans,nans);
	}
	printf("%lld\n",minans);
	return 0;
}
