#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
int maxx;
int anss=0;
struct node2{
	int numm;
	int id;
};
struct node4{
	int zhi;
	int id;
	int timme;
	friend bool operator < (node4 x,node4 y)
	{
		return x.zhi>y.zhi;
	}
};
bool cmp(node2 x,node2 y)
{
	return x.numm>y.numm;
}
int num[100005][5];
node2 s[5];
int ap[100005][5];
int ton[10]={0};
void init()
{
	for(int i=0;i<=100000;i++)
	{
		for(int j=0;j<=3;j++)
		{
			num[i][j]=0;
			ap[i][j]=0;
		}
	}
	for(int i=0;i<=9;i++)
	{
		ton[i]=0;
	}
	anss=0;
	
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		init();
		cin>>n;
		maxx=n/2;
		priority_queue<node4> q[5];
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			s[1]={x,1};
			s[2]={y,2};
			s[3]={z,3};
			sort(s+1,s+1+3,cmp);
			num[i][1]=s[1].id;
			num[i][2]=s[2].id;
			num[i][3]=s[3].id;
			ap[i][1]=s[1].numm-s[2].numm;
			ap[i][2]=s[2].numm-s[3].numm;
			ton[s[1].id]++;
			q[s[1].id].push({ap[i][1],i,1});
			anss+=s[1].numm;
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(ton[j]>maxx)
				{
					while(ton[j]>maxx)
					{
						node4 now=q[j].top();
						q[j].pop();
						int to=now.timme+1;
						ton[j]--;
						ton[num[now.id][to]]++;
						anss-=now.zhi;
						q[num[now.id][to]].push({ap[now.id][to],now.id,to});
					}
				}
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
