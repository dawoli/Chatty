#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c;
int s[1001][2001],l[1001];
bool end1=false;
int f[101][10001],v[101],maxv;
void dfs(int w,int num,int x)
{
	f[x][v[x]++]=num;
	if(x==r+1)
	{
		if(num==c) end1=true;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(i==w) continue;
		for(int j=0;j<l[i];j++)
		{
			if(s[i][j]==num)
			{
				for(int tmp=j+1;tmp<min(l[i],j+k);tmp++)
					dfs(i,s[i][tmp],x+1);
				if(end1) return;
			}
		}
	}
}
void func()
{
	cin>>n>>k>>q;
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
		for(int j=0;j<l[i];j++) cin>>s[i][j];
	}
	for(int i=0;i<q;i++)
	{
		cin>>r>>c;
		end1=false;
		if(r<maxv)
		{
			for(int j=0;j<v[r+1];j++)
				if(f[r+1][j]==c) end1=true;
		}
		else
			dfs(-1,1,1);
		cout<<end1<<endl;
		maxv=r;
	}
	return;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	cin>>t;
	for(int i=0;i<t;i++) func();
	return 0;
}
