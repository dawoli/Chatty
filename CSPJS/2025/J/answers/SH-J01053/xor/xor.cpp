#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int sum;
int ans,s;
bool b[500001];
map<int, map<int, int>> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(s=i;s<=j;s++)
			{
				if(b[s]==1)
				{
					sum=-1;
					break;
				}
				sum^=a[s];
			}
			if(sum==k)
			{
				ans++;
			    for(s=i;s<=j;s++)
			    {
			    	b[s]=1;
				}
			} 
			sum=0; 
		}
	}
	cout<<ans;
	return 0;
} 
