#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int arr1[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,k=0,mn=INT_MAX;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		arr[tmp]++;
		arr1[tmp]++;
		mn=min(mn,tmp);
	}
	int pos=mn;
	int ans=0;
	for(int i=mn+1;i<=100000;i++)
	{
		while(arr[i]&&pos<i)
		{
			if(arr[i]>=arr[pos])
			{
				ans+=arr[pos];
				arr1[i]-=arr[pos];
				arr[pos]=0;
				while(!arr[pos])
					pos++;
			}
			else
			{
				ans+=arr[i];
				arr1[pos]-=arr[i];
				arr[i]=0;
			}
		}
	}
	printf("%d\n",(n-ans));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
