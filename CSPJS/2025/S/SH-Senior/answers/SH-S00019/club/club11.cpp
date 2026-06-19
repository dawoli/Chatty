#include<bits/stdc++.h> 
using namespace std;
int a[100005][5],sum[4],ans,anss=0,n;
int dfs(int x,int y)
{
	sum[x]++;
	cout<<"y="<<y<<endl;
	if(y==n)
	{
		return a[y][x]; 
	}
	else if(x>3) return 0;
	if(sum[x]>n/2)
	{
		
	}
		int xx=0,yy=0,zz=0;
		if(sum[1]<=n/2) xx=dfs(1,y+1);
		cout<<"dfs("<<1<<","<<y+1<<")= "<<xx<<endl;
		if(sum[2]<=n/2) yy=dfs(2,y+1);
		cout<<"dfs("<<2<<","<<y+2<<")= "<<yy<<endl;
		if(sum[3]<=n/2) zz=dfs(3,y+1);
		
		
		cout<<"dfs("<<3<<","<<y+3<<")= "<<zz<<endl;
		if(xx>=yy&&xx>=zz)
		{
			ans+=xx;
		}
		else if(yy>=xx&&yy>=zz)
		{
			ans+=yy;
		}
		else
		{
			ans+=zz;
		}
	
	
	
	
}
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int t;
	cin>>t;
	for(int dbe=0;dbe<t;dbe++)
	{
		cin>>n;
		a[100005][5]={};
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int z=1;z<=3;z++)
		{
			sum[4]={};
			ans=0;
			cout<<"dfs("<<z<<",1): "<<dfs(z,1)<<endl;
			anss=max(anss,dfs(z,1));
		}
		cout<<anss<<endl;
	}
}
