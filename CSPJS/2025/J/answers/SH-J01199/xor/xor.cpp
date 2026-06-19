#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[100005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i = 1;i<=n;i++)
	{
		int tmp=a[i];
		int j = i+1;
		for(j = i+1;j<=n&&tmp!=k;j++)
		{
			tmp=tmp^a[j];
//			printf("tmp:%d j:%d\n",tmp,j);	
		}
		if(tmp==k)
		{
//			printf("i:%d j:%d\n",i,j);
			ans++;
			i=j-1;
		}
	}
	cout << ans;
	return 0;
}

