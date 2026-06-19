/*

|----car_d-----|-------------|
|---------road_length--------|

多测要清空！！！！！！！ 

变量 
road_length道路长度 
car_count车辆个数
car_d车辆驶入点 
car_v车辆初速度
car_a车辆加速度
vis_car车辆是否已经被标记为超速 
spedet_count测速仪个数
overspeed_count超速车辆个数 
least_count最少测速仪数目 
limit_v限速(驶入和驶出时也要判定)
spedet_pos[]测速仪位置,模拟链表加快效率 
spedet_times[]记录每个测速仪检测到的超速车辆编号 

Q1超速车辆个数
Q2最多关闭多少测速仪:
	取每个超速车辆被测速仪i监测为超速的集合的交集
明显超速的区间一定是连续的 
	
步骤：
1）读入数据
2）计算每辆车是否超速，以及在哪个测速仪会被判断为超速,统计超速区间 
3) 

 
 避免浮点数运算 
*/


#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=1e6+5;
//车子信息数组 
struct car
{
	int car_d,car_v,car_a;
}car_all[N];
//测试组数 
int T; 
//见上 
int car_count,spedet_count,road_length,limit_v,overspeed_count,least_count;
bool vis_car[N];
//测速仪信息数组
int spedet_pos[N],spedet_next[N];
vector<int> spedet_times[N];
//并查集部分
int fa[N],sz[N];
int find(int x)
{
	if(fa[x]==-1) return x;
	return fa[x]=find(fa[x]);
}
void add(int a,int b)
{
	int af,bf;
	af=find(a);
	bf=find(b);
	if(af!=bf)
	{
		fa[bf]=af;
		sz[af]+=sz[bf];
	}
}
struct cmp
{
	bool operator()(vector<int> a,vector<int> b)
	{
		int new_found_a=0,new_found_b=0;
		//int new_found_aleft=0x3f3f3f3f,new_found_bleft=0x3f3f3f3f;
		for(int i=0;i<a.size();i++)
		{
			if(find(a[i])==a[i])
			{
				new_found_a++;
				//if(new_found_aleft==0x3f3f3f3f) new_found_aleft=i;
			}
		}
		for(int i=0;i<b.size();i++)
		{
			if(find(b[i])==b[i])
			{
				new_found_b++;
				//if(new_found_bleft==0x3f3f3f3f) new_found_bleft=i;
			} 
		}
//		return new_found_aleft==new_found_bleft?new_found_a<new_found_b:new_found_aleft>new_found_bleft;
		//return a.size()==b.size()?new_found_a<new_found_b:a.size()<=b.size();
		return new_found_a<new_found_b;
	}
};
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		least_count=0;
		overspeed_count=0;
		memset(vis_car,0,sizeof(vis_car));
		memset(fa,-1,sizeof(fa));
		memset(spedet_next,0,sizeof(spedet_next));
		memset(spedet_pos,0,sizeof(spedet_pos));
		memset(car_all,0,sizeof(car_all)); 
		memset(spedet_times,0,sizeof(spedet_times));
		scanf("%d%d%d%d",&car_count,&spedet_count,&road_length,&limit_v);
		sz[0]=1;
		for(int j=1;j<=car_count;j++)
		{
			scanf("%d%d%d",&car_all[j].car_d,&car_all[j].car_v,&car_all[j].car_a);
			sz[j]=1;
		}
		int last=-1;
		for(int j=1;j<=spedet_count;j++)
		{
			int x;
			scanf("%d",&x);
			spedet_pos[x]=1;
			if(last!=-1) spedet_next[last]=x;
			last=x;
		}
		spedet_next[last]=0x3f3f3f3f;
		//Q1
		for(int j=1;j<=car_count;j++)
		{
			//k为位置 
			for(int k=car_all[j].car_d;k<=road_length;k=spedet_next[k])
			{
				while(spedet_pos[k]!=1)
				{
					k++;
				}
				if(2*car_all[j].car_a*(k-car_all[j].car_d)+car_all[j].car_v*car_all[j].car_v>limit_v*limit_v)
				{
					spedet_times[k].push_back(j);
					if(vis_car[j]==0)
					{
						vis_car[j]=true;
						overspeed_count++;
					}
				}
			}
		}
		//Q2
		priority_queue<vector<int>,vector<vector<int> >,cmp > spedet_times_sorted;
		for(int j=0;j<=road_length;j++)
		{
			if(spedet_times[j].size())
			{
				spedet_times_sorted.push(spedet_times[j]);
			}
		}
		for(auto j=spedet_times_sorted.top();spedet_times_sorted.size();j=spedet_times_sorted.top())
		{
//			if(i==10)
//			{
//				for(int k=0;k<j.size();k++)
//				{
//					cout<<j[k]<<" ";
//				}
//				cout<<endl;
//			}
			bool flag=true;
			for(int k=0;k<j.size();k++)
			{
				if(flag&&find(j[k])==j[k])
				{
					flag=false;
					least_count++;
				}
				add(0,j[k]);
			}
			//cout<<endl;
			if(sz[0]==overspeed_count+1) break;
			spedet_times_sorted.pop();
		}
		
		printf("%d %d\n",overspeed_count,spedet_count-least_count);
	}
	return 0;
}
