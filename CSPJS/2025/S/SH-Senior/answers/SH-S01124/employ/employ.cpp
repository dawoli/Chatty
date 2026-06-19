#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int max_n=505;
const int mod=998244353;
bool can[max_n],vis[max_n];
int patient[max_n],order[max_n];
int ans=0;
bool judge(int *order,const int n,const int m)
{
	int give_up=0;
	for(int i=1;i<=n;i++)
		if(give_up>=patient[order[i]] || !can[i])
			give_up+=1;
	return (n-give_up)>=m;
}
void dfs(int people_left,int n,int m)
{
	if(!people_left)
	{
		ans+=(judge(order,n,m) ? 1 : 0);
		ans %= mod;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=true;
			order[n-people_left+1]=i;
			dfs(people_left-1,n,m);
			vis[i]=false;
		}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		can[i]=c-'0';
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		cin>>patient[i];
	sort(patient+1,patient+1+n);
	dfs(n,n,m);
	cout<<ans;
	return 0;
}