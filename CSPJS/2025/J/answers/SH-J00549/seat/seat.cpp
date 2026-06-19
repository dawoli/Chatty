#include<iostream>
#include<algorithm>
using namespace std;
int n,m,R;
int arr[111];
int seat[11][11];
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int a,int b)
{
	if(a>m)
	{
		return;
	}
	if(a%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			seat[i][a]=arr[b++];
		}
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			seat[i][a]=arr[b++];
		}
	}
	dfs(a+1,b);
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>arr[i];
	}
	R=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(seat[i][j]==R)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
