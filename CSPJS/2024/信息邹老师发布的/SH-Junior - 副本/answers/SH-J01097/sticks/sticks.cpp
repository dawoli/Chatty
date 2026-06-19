#include <iostream>
#include <cstdio>
using namespace std;
long long amount[]={6,2,5,5,4,5,6,3,7,6},ans=2147483647,T,n;
void dfs(long long a,long long b)
{
	if(a<0||b>=ans)return;
	if(a==0)
	{
		ans=min(b,ans);
		return ;
	}
	if(b==0)
	{
		for(long long i = 1;i<=9;i++)
		{
			dfs(a-amount[i],i);
		}
	}
	else
	{
		for(long long i = 0;i<=9;i++)
		{
			dfs(a-amount[i],b*10+i);
		}
	}
	return ;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=2147483647;
		cin>>n;
		if(n<2)
		{
			cout<<-1<<endl;
			continue;
		}
		dfs(n,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
