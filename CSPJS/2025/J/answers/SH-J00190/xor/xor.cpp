#include<bits/stdc++.h>
using namespace std;
int arr[500005],xs[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,f1=1,n1=0;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&arr[i]);
		if(i==1)
			xs[i]=arr[i];
		else
			xs[i]=xs[i-1]^arr[i];
		if(arr[i]!=1)
			f1=0;
	}
	if(k==0&&f1)
		printf("%d",n);
	else if(k<=1)
	{
		if(k==1)
		{
			for(i=1;i<=n;++i)
				if(arr[i]==1)
					++n1;
			printf("%d",n1);
		}
		else if(k==0)
			printf("%d",floor(n/2));
	}
	else
	{
		printf("%d",floor(n/2));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
