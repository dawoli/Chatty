#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[200005]={},num[10]={},cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			num[arr[i]]++;
		}
		for(int i=0;i<=9;i++)
		{
			cnt+=num[i]/2*i;
		}
		cout<<cnt<<endl
	}
	fclose(stdin);
	fclose(stdout);
}
