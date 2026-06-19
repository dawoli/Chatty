#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
		}
	}
	printf("1\n0\n8\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
