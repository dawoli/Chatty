#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;
const int max_n=300;
int order[max_n],ans=-1;
int stu[max_n][3];
void init()
{
	memset(order,-1,sizeof(order));
	ans=-1;
	memset(stu,0,sizeof(stu));
	return ;
}
void dfs(const int n,int people_left,int *lim)
{
	if(!people_left)
	{
		int t=0;
		for(int i=1;i<=n;i++)
			t+=stu[i][order[i]];
		ans=max(ans,t);
		return ;
	}
	for(int i=0;i<3;i++)
		if(lim[i]>0)
		{
			lim[i]-=1;
			order[people_left]=i;
			dfs(n,people_left-1,lim);
			lim[i]+=1;
		}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		init();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>stu[i][0]>>stu[i][1]>>stu[i][2];
		int lim[3]={n/2,n/2,n/2};
		dfs(n,n,lim);
		cout<<ans<<endl;
	}
	return 0;
}
