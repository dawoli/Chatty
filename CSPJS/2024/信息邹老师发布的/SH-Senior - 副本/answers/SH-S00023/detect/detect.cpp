#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node
{
	int d,v,a;
	bool operator < (const node& c2) const
	{
		return d<c2.d;
	}
	double sp(int pos)
	{
		if(pos<d) return -1;
		int t=v*v+2*a*(pos-d);
		if(t>=0) return t;
		return -1;
	}
}car[N];
int f[N];
int mac[N];//machine
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		bool flagA=1;
		int n,m,l,v;//车辆数，摄像头数，道路长度，限速
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++)
		{
			int t1,t2,t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			if(t3!=0) flagA=0;
			car[i].d=t1;
			car[i].v=t2;
			car[i].a=t3;
		}
		
		
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&mac[i]);
		}
		sort(mac+1,mac+1+m);
		
		if(flagA)//加速度全为0
		{
			vector<int> len;//超速的车辆从len位置开始超速 
			int ans1=0;
			sort(car+1,car+n+1);//按驶入位置排序
			for(int i=1;i<=n;i++)
			{
				if(car[i].v>v)//超速
				{
					f[i]=1;
					len.push_back(car[i].d);
				}
				else f[i]=0; 
			}
			for(int i=0;i<len.size();i++)
			{
				if(len[i]<=mac[m]) ans1++;
			}
			int ans2=m-1;
			if(ans1==0) ans2++;
			printf("%d %d\n",ans1,ans2);
			
			continue;
		} 
	}
}
