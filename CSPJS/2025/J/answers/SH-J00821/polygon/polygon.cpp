#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
int a[5010];
void dfs(int sum,int maxn,int x,int y)
{
	if(x>n)
	{
		if(sum>maxn*2&&y>=3){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	dfs(sum+a[x],max(maxn,a[x]),x+1,y+1);
	dfs(sum,maxn,x+1,y);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
	}
	dfs(0,0,1,0);
	cout <<cnt%998244353;
	return 0;
}
