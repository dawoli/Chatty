#include<bits/stdc++.h>
using namespace std;
int val[500010],n,k,ans,a[500010],l,lst;
map<int,int> pl;
struct stu{
	int l,r;
}x[500010];
bool cmp(stu a,stu b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
		a[i]=a[i-1]^val[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((a[i-1]^a[j])==k)
			{
				l++;
				x[l].l=i;
				x[l].r=j;
				break;
			}
		}
	}
	sort(x+1,x+l+1,cmp);
	for(int i=1;i<=l;i++)
	{
		if(lst<x[i].l)
		{
			ans++;
			lst=x[i].r;
		}
	}
	cout<<ans;
	return 0;
}
