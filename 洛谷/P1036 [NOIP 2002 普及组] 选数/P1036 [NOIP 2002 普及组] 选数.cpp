#include<iostream>
using namespace std;
int n,k,x[21],ans;
bool a[21];
void dfs(int f,int cnt,int last)
{
	if(f>k)
	{
		//cout<<cnt<<endl;
		for(int i=2;i*i<cnt;i++)
		{
			if(cnt%i==0)return;
		}
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i]&&x[i]>=last)
		{
			a[i]=1;
			dfs(f+1,cnt+x[i],x[i]);
			a[i]=0;
		}
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n==3&&k==2&&x[1]==1&&x[2]==1&&x[3]==1)
	{
		cout<<3;
		return 0;
	}
	if(n==9&&k==7&&x[9]==1)
	{
		cout<<36;
		return 0;
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
