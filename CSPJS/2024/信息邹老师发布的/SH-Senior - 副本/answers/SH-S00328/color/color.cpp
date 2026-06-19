#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2005;
int t,n;
int a[200005];
bool mem[maxn][maxn];
int cache[maxn][maxn];
//多测不清空，爆零两行泪 

int dfs(int ind,int last_red_ind,int last_blue_ind)
{
	if(ind>n)
	{
		return 0;
	}
	if(mem[last_red_ind][last_blue_ind])
	{
		return cache[last_red_ind][last_blue_ind];
	}
	int ret=0;
	//当前数染红 
	int print_cur_red=dfs(ind+1,ind,last_blue_ind);
	if(a[last_red_ind]==a[ind])
	{
		print_cur_red+=a[ind];
	}
	ret=max(ret,print_cur_red);
	//当前数染蓝
	int print_cur_blue=dfs(ind+1,last_red_ind,ind);
	if(a[last_blue_ind]==a[ind])
	{
		print_cur_blue+=a[ind];
	}
	ret=max(ret,print_cur_blue);
	mem[last_red_ind][last_blue_ind]=1;
	cache[last_red_ind][last_blue_ind]=ret;
	return ret;
}

signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t-->0)
	{
		memset(mem,0,sizeof(mem));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<dfs(1,0,0)<<endl;
	}
	return 0;
}
