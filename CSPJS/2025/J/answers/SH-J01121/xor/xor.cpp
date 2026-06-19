#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,m,cnt,maxv,past;
int a[maxn],cnt1;

struct mode
{
	int l,r;
}b[maxn];


bool check(int l,int r){
	return (a[r]^a[l-1])==k; 
}
bool cmp(mode a,mode b)
{
	return a.l<b.l;
}

void dfs(int x,int r)
{
	if(x>cnt)
	{
		maxv=max(maxv,cnt1);
	}
	if(b[x].l>r)
	{
		cnt1++;
		dfs(x+1,b[x].r);
		cnt1--;
		dfs(x+1,r);
	}
}
	

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		a[i]=a[i-1]^m;
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if(check(l,r))
			{
				b[++cnt]={l,r};
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	dfs(1,0);
	cout<<maxv;
	return 0;
}
