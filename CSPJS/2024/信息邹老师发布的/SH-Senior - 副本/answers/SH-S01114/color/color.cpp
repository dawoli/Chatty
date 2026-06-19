#include<bits/stdc++.h>
using namespace std;
int arr[200005];
bool visited[200005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int n,i,t,j;
	long long sum;
	scanf("%d",&t);
	for(i=0;i<t;++i)
	{
		sum=0;
		memset(visited,false,sizeof(visited));
		scanf("%d",&n);
		for(j=0;j<n;++j)
			scanf("%d",&arr[j]);
		sort(arr,arr+n);
		for(j=0;j<n;++j)
		{
			int t=arr[j];
			if(visited[t])
				sum+=t;
			else
				visited[t]=true;
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
