#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
struct node
{
	int l,r;
}b[500005];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		if(sum==k) b[++cur].l=i,b[cur].r=i;
		for(int j=i+1;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k) b[++cur].l=i,b[cur].r=j;
		}
	}
	sort(b+1,b+cur+1,cmp);
	int Las_En=-1,ans=0;
	for(int i=1;i<=cur;i++)
	{
		if(b[i].l>Las_En)
		{
			ans++;
			Las_En=b[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;
}
