#include<bits/stdc++.h>
using namespace std;
int arr[100005];
char tmp[10];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",tmp);
		int k=tmp[0]+tmp[1]*10;
		arr[k]++;
	}
	int ans=0;
	for(int i=1;i<=10000;i++)
	{
		if(arr[i]>0)
		{
			ans++;
		}
	}
	printf("%d\n",(52-ans));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
