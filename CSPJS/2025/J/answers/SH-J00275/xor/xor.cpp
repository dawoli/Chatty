#include<bits/stdc++.h>
using namespace std;
int n,m;
long long w[500010];
long long d[500010];
struct node
{
	int u,v;
}a[2000010];
bool cmp(node a,node b)
{
	if(a.v!=b.v)
	{
		return a.v<b.v;
	}
	return a.u<b.u;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		d[i]=d[i-1]^w[i];
	}
	int ans=0;
	d[0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i+1==j)
			{
				if(w[i]==0){
				ans++;
				a[ans].u=i+1;
				a[ans].v=j;}
				continue;
			}
			if(d[j]^d[i]==m)
			{
				ans++;
				a[ans].u=i+1;
				a[ans].v=j;
			}
		}
	}
	sort(a+1,a+ans+1,cmp);
	int v1=a[1].v;
	int cnt=1;
	for(int i=2;i<=ans;i++)
	{

		if(a[i].u<=v1)continue;
		cnt++;
		v1=a[i].v;

	}
	cout<<cnt<<endl;
	return 0;
}
