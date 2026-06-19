#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,q;
		int arr[200005][200005]={};
		cin>>n>>k>>q;
		int maxn=0;
		for(int i=1;i<=n;i++)      
		{
			cin>>arr[i][0];
			for(int j=1;j<=arr[i][0];j++)
			{
				cin>>arr[i][j];
				if(arr[i][j]>=maxn) maxn=arr[i][j];
			}
		}
		while(q--)
		{
			int r,c;
			cin>>r>>c;
			if(c>=maxn)
			{
				cout<<0;
				continue;
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
}
