#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const long long MOD=998244353;
long long cnt;
int n;
long long a[5010];
bool mp[1<<22];
void dfs(int deep,int vis,int num,int mx)
{
	if(mp[vis]) return;
	mp[vis]=1;
	if(deep>=2&&num>a[mx])
	{
		//cout<<vis/16<<" "<<vis%16/8<<" "<<vis%8/4<<" "<<vis%4/2<<" "<<vis%2<<endl;
		cnt++;
	}
	for(int i=1;i<mx;i++)
	{
		if((vis&(1<<(i-1)))==0)
		{
			dfs(deep+1,vis|(1<<(i-1)),num+a[i],mx);
		}
	}
}
void solve1()
{
	for(int i=3;i<=n;i++)
	{
		dfs(0,(1<<(i-1)),0,i);
	} 
	cout<<cnt%MOD<<endl;
}
long long xuanze(int x,int y)
{
	int num=1;
	for(int i=1;i<=y;i++)
	{
		num*=(x-i+1);
		num/=i;
		num%=MOD;
	}
	return num;
}
void solve2()
{
	for(int i=3;i<=n;i++)
	{
		cnt+=xuanze(n,min(i,n-i));
		cnt%=MOD;
	}
	cout<<cnt<<endl;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20)
	{
		solve1();
		return 0;
	}
	else
	{
		solve2();
		return 0;
	}
	return 0;
} 
