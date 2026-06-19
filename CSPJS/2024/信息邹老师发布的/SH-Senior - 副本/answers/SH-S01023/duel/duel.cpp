#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,arr[100005]={},flag[100005]={},cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]==1) a++;
		else b++;
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(arr[i]>arr[j]&&flag[j]==0)
			{
				cnt++;
				flag[j]=1;
				break;
			}
		}
	}
	cout<<n-cnt;
	fclose(stdin);
	fclose(stdout);
}

//Z*L#LH%9
