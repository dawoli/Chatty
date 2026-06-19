#include<iostream>
using namespace std;
int s[4],a[85],maxx;
void dfs(int sum,int no,int now)
{
	sum+=now;
	if(no==3)
	{
		a[sum]++;
		return;
	}
	for(int i=1;i<=s[no+1];i++)
	{
		dfs(sum,no+1,i);
	}
}
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	cin>>s[1]>>s[2]>>s[3];
	dfs(0,0,0);
	for(int i=1;i<=84;i++)
	{
		if(a[i]>maxx)maxx=a[i];
	}
	cout<<maxx;
	return 0;
}
