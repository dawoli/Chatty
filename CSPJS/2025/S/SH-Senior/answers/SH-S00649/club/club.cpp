#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3]; 
int dfs(int id,int x,int y,int z,int cnt)
{
	if(id>n)
	{
		if(x>n/2||y>n/2||z>n/2)return 0;
		else return cnt;
	}
	return max(dfs(id+1,x+1,y,z,cnt+a[id][0]),max(dfs(id+1,x,y+1,z,cnt+a[id][1]),dfs(id+1,x,y,z+1,cnt+a[id][2])));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		cout<<dfs(1,0,0,0,0)<<"\n";
	}
	return 0;
} 


