#include<bits/stdc++.h>
using namespace std;

int n,t;
int a[5][100100];
int num;
struct node{
	int t,v;
};
vector<node> p[5];
int ps[5];

bool cmp(node x,node y)
{
	return x.v<y.v;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--)
	{
		//初始化 
		num=0;
		p[1].clear();ps[1]=0;
		p[2].clear();ps[2]=0;
		p[3].clear();ps[3]=0;
		//输入 
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int maxn=-1;
			int mst=-1;
			for(int j=1;j<=3;j++)
			{
				cin>>a[j][i];
				if(a[j][i]>maxn)//找最大值 
				{
					maxn=a[j][i];
					mst=j;
				}
			}
			//记录数值 
			num+=maxn;
			ps[mst]++;
			int mn=0x3f3f3f3f;
			int tmn=-1;
			for(int j=1;j<=3;j++)
			{
				if(j==mst) continue;
				if(mn  >  abs ( a[mst][i] - a[j][i] ) )  mn=abs ( a[mst][i] - a[j][i] ) , tmn=j;
			}
			p[mst].push_back({tmn,mn});
		}
		//寻找不满足条件的
		
//		cout<<num<<endl;//debug
		
		for(int i=1;i<=3;i++)
		{
			
			//debug
//			for(auto d : p[i])
//			{
//				cout<<d.t<<":"<<d.v<<' ';
//			 } 
//			cout<<endl;
			//end debug
			
			if(ps[i]>n/2)
			{
				sort(p[i].begin(),p[i].end(),cmp);
				int deln=0;
				for(int j=0;ps[i]-deln > n/2 ; j++)//删除 
				{
					if(ps[p[i][j].t] < n/2)
					{
						num-=p[i][j].v ;
						ps[p[i][j].t]+=1;
						deln+=1;
//						cout<<p[i][j].t<<":"<<p[i][j].v<<"!\n";
					}
				}
			}
		} 
		cout<<num<<endl;
	}
	return 0;
}
