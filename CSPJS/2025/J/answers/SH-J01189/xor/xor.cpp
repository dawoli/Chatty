#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0,ans1=0,count=0;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		ans1=0;
	int left=i;
	for(int j=0;j<n;j++)
	{
		count=a[left];
		count=count^a[j];
		if(count==k)
		{
			ans1++;
			left=j+1;
		}
		if(ans1>ans)
		{
			ans=ans1;
		}
	}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
