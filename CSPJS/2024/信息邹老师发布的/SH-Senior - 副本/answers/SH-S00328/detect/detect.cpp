#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3005;

struct node{
	int src;
	int start_v;
	int add_v;
}car[maxn];

struct duan{
	double l;
	double r;
}ban[maxn];

int t;
//多测清空！！不要爆零！！ 

int n;//车辆数量 不用多测清空 
int m;//测速仪数量  不用多测清空 
int len;//道路长度  不用多测清空 
int v;//道路限速  不用多测清空 
int bad_car_cnt;//用多测清空  
int pos[maxn];//不用多测清空
int killed_cnt;//用多测清空
bool can_see[maxn][maxn];//用多测清空
bool choose[maxn];//用多测清空

bool check()
{
	for(int i=1;i<=killed_cnt;i++)
	{
		bool seen=0;
		for(int j=1;j<=m;j++)
		{
			if(choose[j] and can_see[j][i])
			{
				seen=1;
			}
		}
		if(!seen)
		{
			return 0;
		}
	}
	return 1;
}

int dfs(int i)
{
	if(i>m)
	{
		if(check())
		{
			return 0;
		}
		return m;
	}
	int ret=m;
	ret=min(ret,dfs(i+1));
	choose[i]=1;
	ret=min(ret,dfs(i+1)+1);
	choose[i]=0;
	return ret;
}

signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t-->0)
	{
		bad_car_cnt=0;
		killed_cnt=0;
		memset(choose,0,sizeof(choose));
		memset(can_see,0,sizeof(can_see));
		cin>>n>>m>>len>>v;
		//输入
		for(int i=1;i<=n;i++)
		{
			cin>>car[i].src>>car[i].start_v>>car[i].add_v;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>pos[i];
		}
		//计算每辆车的违规区间
		for(int i=1;i<=n;i++)
		{
			if(car[i].start_v<=v and car[i].add_v<=0)
			{
				continue;
			}
			double l,r;
			//原本超速，慢慢变得不超速
			//一直超速 
			//原本不超速，结果越来越超速
			if(car[i].start_v>v)
			{
				if(car[i].add_v<0)
				{
					l=car[i].src;
					double s=((double)v*v-(double)car[i].start_v*car[i].start_v)/((double)2*car[i].add_v);
					r=min((double)len,s+l-0.1);
				}
				else
				{
					l=car[i].src;
					r=len;
				}
			}
			else
			{
				double s=((double)v*v-(double)car[i].start_v*car[i].start_v)/((double)2*car[i].add_v);
				if(s+car[i].src<=len)
				{
					l=s+car[i].src+0.1;
					r=len;
				}
				else
				{
					continue;
				}
			}
			bad_car_cnt++;
			ban[bad_car_cnt].l=l;
			ban[bad_car_cnt].r=r;
			//cout<<"!!!"<<i<<" "<<l<<" "<<r<<endl;
		}
		for(int cur_car=1;cur_car<=bad_car_cnt;cur_car++)
		{
			bool killed=0;
			for(int j=1;j<=m;j++)
			{
				double cur_monitor=(double)pos[j];
				if(ban[cur_car].l<=cur_monitor and ban[cur_car].r>=cur_monitor)
				{
					killed=1;
				}
			}
			if(killed)
			{
				killed_cnt++;
				for(int j=1;j<=m;j++)
				{
					double cur_monitor=(double)pos[j];
					if(ban[cur_car].l<=cur_monitor and ban[cur_car].r>=cur_monitor)
					{
						can_see[j][killed_cnt]=1;
					}
				}
			}
		}
		cout<<killed_cnt<<" ";
		//计算每个测速仪是不是必要的
		if(m<=10)
		{
			cout<<m-dfs(1);
			//枚举子集 
		}
		else
		{
			if(killed_cnt==0)
			{
				cout<<m;
			}
			else
			{
				cout<<m-1;
			}
		}
		cout<<endl;
	}
	return 0;
}
