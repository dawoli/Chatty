#include<bits/stdc++.h>
using namespace std;
int a[100005],sum[100005];
bool att[100005];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	sort(a+1,a+1+n,cmp);	
	for(int i=1;i<=n;i++)
	{
		sum[a[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{
		int t=sum[a[i]];
		while((a[t]==a[i]||(att[t]))&&t<=n)t++;
		if(t<=n)
		{
			att[t]=1;
			ans++;
		}
	}
	cout<<n-ans;
	fclose(stdin);
	fclose(stdout);
}

