#include<bits/stdc++.h>

using namespace std;

int n;

int a[100500];

int vis1[100500];

int vis2[100500];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans = n;
	for(int i = 1;i <= n;i++)
	{
		if(vis1[i] == 1)continue;
		for(int j = i+1;j <= n;j++)
		{
			if(vis1[j] == 1 || vis2[j] == 1)continue;
			if(a[j] > a[i])
			{
				ans--;
				vis2[j] = vis1[i] = 1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
