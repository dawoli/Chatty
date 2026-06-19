#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct member{
	int a,b,c;
}p[N];
int b[4],ans,n;
void dfs(int i,int a,int b,int c,int sum)
{
	if(i==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	if(a<n/2)dfs(i+1,a+1,b,c,sum+p[i].a);
	if(b<n/2)dfs(i+1,a,b+1,c,sum+p[i].b);
	if(c<n/2)dfs(i+1,a,b,c+1,sum+p[i].c);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b>>p[i].c;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
