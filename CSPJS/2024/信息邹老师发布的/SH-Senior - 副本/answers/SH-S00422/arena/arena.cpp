#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int N=1e5+10;
int ax[N],a[N],c[N];
string s[N];
int tmp[N];
int depth;
int log2[N];
long long res=0;

void dfs(int u)
{
	if(u==0)
	{
		res=tmp[0];
		return;
	}
	for(int i=0;i<(1<<(u-1));i++)
	{
		if(s[depth-u+1][i]=='1')
		{
			if(tmp[i*2+1]>=depth-u+1)
				tmp[i]=tmp[i*2+1];
			else
				tmp[i]=tmp[i*2];
		}
		else
		{
			if(tmp[i*2]>=depth-u+1)
				tmp[i]=tmp[i*2+1];
			else
				tmp[i]=tmp[i*2];
		}
	}
	dfs(u-1);
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>ax[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	int cnt=1;
	log2[1]=0;
	for(int i=1;i<=n;i++)
	{
		log2[i]=cnt;
		if(i%2==0)
			cnt++;
	}
	cout<<log2[5]<<"xxx"<<endl;
	for(int i=1;i<=log2[n];i++)
		cin>>s[i];
	int T;
	cin>>T;
	while(T--)
	{
		int x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			a[i]=ax[i]^x[i%4];
		long long ans=0;
		for(int k=1;k<=m;k++)
		{
			memcpy(tmp,a,sizeof(a));
			depth=log2[c[k]];
			res=0;
			dfs(depth);
			for(int j=c[k]+1;j<=n;j++)
				res+=j;
			ans=(res*k)^ans;
		}
		cout<<ans<<endl;
	}
    return 0;
}
