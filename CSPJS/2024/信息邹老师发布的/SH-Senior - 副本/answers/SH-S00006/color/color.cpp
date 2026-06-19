#include <bits/stdc++.h>
using namespace std;
int num;
unsigned long long ans,nowans,r,b;
unsigned long long clo[200200];
void dfs(int step)
{
	if(step==num)
	{
		ans=max(ans,nowans);
		return;
	}
	if(clo[step]!=r&&clo[step]!=b)
	{
		int temp=r;
		r=clo[step];
		dfs(step+1);
		r=temp;
		temp=b;
		b=clo[step];
		dfs(step+1);
		b=temp;
		return;
	}
	if(clo[step]==r)
	{
		nowans+=r;
		dfs(step+1);
		nowans-=r;
	}
	else
	{
		nowans+=b;
		dfs(step+1);
		nowans-=b;
	}
	return;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int times;
	cin>>times;
	while(times>0)
	{
		cin>>num;
		memset(clo,0,sizeof(clo));
		for(int i=0;i<num;i++)
			cin>>clo[i];
		nowans=0,ans=0;
		r=clo[0],b=0;
		dfs(1);
		cout<<ans<<endl;
		times--;
	}
}
