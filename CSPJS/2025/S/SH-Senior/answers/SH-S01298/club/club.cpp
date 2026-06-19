#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,a[maxn][4];
int v[4],sper[maxn];
long long ans,temp;
void file()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
void init()
{
	ans=0;
	temp=0;
	sper[0]=0;
}
void read()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	for(int i=n;i>=1;i--)
        sper[i]=sper[i+1]+max(a[i][1],max(a[i][2],a[i][3]));
}
void dfs(int i)
{
	if(i>n)
	{
		ans=max(ans,temp);
		return;
	}
	if(temp+sper[i]<=ans) return;
	for(int j=1;j<=3;j++)
	{
		if(v[j]>=(n/2)) continue;
		temp+=a[i][j];
		v[j]++;
		dfs(i+1);
		temp-=a[i][j];
		v[j]--;
	}
	return;
}
int main()
{
	file();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		init();
		read();
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
