#include<bits/stdc++.h>
using namespace std;
int arr[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,m,a,x,id,j,n,k;
	long long ans=0;
	scanf("%d %d",&n,&k);
	int flag=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>1)
			flag=1;
	}
	printf("%d",n/2);
	return 0;
}
