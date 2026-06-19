#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=(1<<18)+5;
const int mod=998244353;
string str;
int n,m;
bool lu[20];
int c[20];
bool vis[20];
bool mem[maxn][20];
int cache[maxn][20];

int decode()
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		ret*=2;
		ret+=vis[i];
	}
	return ret;
}

int dfs(int i,int j)
{
	int cod=decode();
	if(mem[cod][j])
	{
		return cache[cod][j];
	}
	if(i>n)
	{
		if(j<=n-m)
		{
			return 1;
		}
		return 0;
	}
	int ret=0;
	for(int k=1;k<=n;k++)
	{
		if(!vis[k])
		{
			vis[k]=1;
			if(c[k]>j and lu[i])
			{
				ret+=dfs(i+1,j);
				ret%=mod;
			}
			else
			{
				ret+=dfs(i+1,j+1);
				ret%=mod;
			}
			vis[k]=0;
		}
	}
	//cout<<"!!!"<<i<<" "<<j<<" "<<ret<<" "<<vis[1]<<" "<<vis[2]<<" "<<vis[3]<<endl;
	mem[cod][j]=1;
	cache[cod][j]=ret;
	return ret;
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		lu[i+1]=str[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<dfs(1,0);
	return 0;
}
