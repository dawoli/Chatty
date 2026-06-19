#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6;
int n,k,cnt=0,ans=0;
int arr[N];
int jisuan(int a,int b)
{
	int res=arr[a];
	if(a==b)
	{
		return res;
	}
	for(int i=a+1;i<=b;i++)
	{
		res=res^arr[i];
	}
	return res;
}
bool check(int a,int b)
{
	if(jisuan(a,b)==k)
	{
		return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
			{
				if(check(j,k))
				{
					j=k;
					cnt++;
					break;
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
