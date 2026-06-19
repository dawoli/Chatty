#include<bits/stdc++.h>
using namespace std;
int n,k,t,a[1005],b[1005][1005],ans=1,now;
struct node
{
	int p,q;
}c[1005];
bool cmp(node x,node y)
{
	return x.p<y.p;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=i;j++)
		{
			b[j][i]=(b[j][i-1]^a[i]);
			if(b[j][i]==k)
			{
				t++;
				c[t].p=j,c[t].q=i;
			}
		}
	}
	
	sort(c+1,c+t+1,cmp);
	if(t==0)
	{
		cout<<"0";
		return 0;
	}
	now=c[1].q;
	for(int i=1;i<=t;i++)
	{
		if(now<c[i+1].p)
		{
			ans++;
			now=c[i+1].q;
		}
		else
		{
			now=min(now,c[i+1].q);
		}
	}
	cout<<ans;
	return 0; 
}
