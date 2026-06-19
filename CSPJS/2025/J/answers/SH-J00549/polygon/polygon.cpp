#include<iostream>
#include<algorithm>
using namespace std;
int n,sum=0;
int arr[5555];
unsigned long long cnt=0;
void dfs(int dep,int lim,int st)
{
	if(dep==1)
	{
		for(int i=st;i<=n;i++)
		{
			if(sum>arr[i])
			{
				cnt++;
			}
			else
			{
				break;
			}
		}
		return;
	}
	for(int i=st;i<=lim;i++)
	{
		sum+=arr[i];
		dfs(dep-1,lim+1,i+1);
		sum-=arr[i];
	}
}
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i=3;i<=n;i++)
	{
		dfs(i,n-i+1,1);
	}
	cout<<cnt%998244353;
	return 0;
}
