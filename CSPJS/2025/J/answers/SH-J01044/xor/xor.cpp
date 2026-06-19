#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll n,k,a[N];
int plan_A()
{
	int num=0;
	for(int i=1;i<=n;i++) if(a[i]==0) num++;
	return num; 
}
int plan_B()
{
	int num=0;
	for(int i=1;i<=n;i++) if(a[i]==1) num++;
	return num;
}
int plan_C()
{
	int num=0;
	for(int i=1;i<=n;i++) if(a[i]==255) num++;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((a[i]^a[j]) == 255) num++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j;k<=n;k++) if(((a[i]^a[j])^a[k]) == 255) num++;
		}
	}
	return num;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0)
	{
		cout<<plan_A();
		return 0;
	}
	if(k==1)
	{
		cout<<plan_B();
		return 0;
	}
	cout<<plan_C();
	return 0;
}
