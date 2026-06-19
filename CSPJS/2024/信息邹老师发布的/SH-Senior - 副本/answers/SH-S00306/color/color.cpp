#include <bits/stdc++.h>
using namespace std;
int num[200001];
int find(int l,int r,int a)
{
	for(int i=l;i<=r;i++)
	{
		if(num[i]==a)
		{
		return i;
	}
	}
	return 0;
}
int findb(int l,int r,int a)
{
	for(int i=l;i<r;i++)
	{
		if(num[i]>=a)return i;
	}
	return 0;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin >> t;
	while(t--)
	{
		int ans=0;
		int n;cin >> n;
		for(int i=1;i<=n;i++)cin >> num[i];
		for(int i=1;i<=n;i++)
		{
			if(num[i]==-1)continue;
			int a=find(i+1,n,num[i]);
			if(a==0){
			continue;}
			int b=findb(i+1,a,num[i]);
			if(b/2&&b!=a-1){
			continue;}
			ans+=num[i];
			num[a]=-1;
			if(a-i>1)i=a-2;
		}
		cout << ans;
	}
}
