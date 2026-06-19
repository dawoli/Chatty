#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100001]={},ma=0,mi=200000;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[x]++;
		if(x>ma) ma=x;
		if(x<mi) mi=x;
	}
	int t=0,num=a[mi],to[100001]={},fr=1,be=1;to[1]=mi;
	for(int i=mi+1;i<=ma;i++)
	{
		if(!a[i]) continue;
		else if(a[i]<num)
		{
			int k=a[i];num-=k;t+=k;
			for(int j=fr;j<=be;j++)
				if(a[to[j]]-k>0)
				{
					a[to[j]]-=k;
					break;
				}
				else if(a[to[j]]==k)
				{
					a[to[j]]=0;
					fr++;
					break;
				}
				else
				{
					k-=a[to[j]];
					a[to[j]]=0;
					fr++;
				}
			to[be+1]=i;be++;num+=a[i];
		}
		else
		{
			fr=be+1;
			a[be+1]=i;
			be++;
			t+=num;
			num=a[i];
		}
	}
	cout<<n-t;
	return 0;
}
