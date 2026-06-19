#include <bits/stdc++.h>
using namespace std;
int sb[15]={6,2,5,5,4,5,6,3,7,6};
string ans,num;
void dfs(int sum,int step)
{
	if(sum==0)
	{
		for(int i=0;i<step;i++)
		{
			cout<<num[i];
		}
		return;
	}
	if(step==0)
	{
		for(int i=9;i>=1;i++)
		{
			if(sum>=sb[i])
			{
				num[0]=(i+'0');
				dfs(sum-sb[i],step+1);
				num[0]='0';
			}
		}
	}else
	{
		for(int i=9;i>=0;i++)
		{
			if(sum>=sb[i])
			{
				num[step]=(i+'0');
				dfs(sum-sb[i],step+1);
				num[step]='0';
			}
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		if(n<2)
			cout<<-1<<endl;
		else{
			ans="-1";
			dfs(n,0);
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

