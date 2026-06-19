#include<bits/stdc++.h>
using namespace std;
int arr[15]={6,2,5,5,4,5,6,3,7,6};
char str[1000005],str1[1000005];
int flag=0,n,k;
inline void dfs(int layer,int sum,int s)
{
	int i;
	if(layer==0&&flag==0&&sum==0)
		k=1;
	else
		k=0;
	if(layer>=s&&sum!=n)
		return; 
	if(layer>=s&&sum==n)
	{
		if(flag==0)
		{
			strcpy(str1,str);
			flag=1;
		}
		else
		{
			if(strcmp(str,str1)<0)
				strcpy(str1,str);
		}
		return;
	}
	for(i=0;i<=9;++i)
	{
		if(k==1)
			i=1;
		str[layer]=i+'0';
		dfs(layer+1,sum+arr[i],s);
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(str1,0,sizeof(str1));
		flag=0;
		if(n<=1)
		{
			printf("-1\n");
			continue;
		}
		if(n%7==0)
		{
			for(i=0;i<n/7;++i)
				printf("8");
			printf("\n");
			continue;
		}
		if((n-1)%7==0)
		{
			printf("16");
			for(i=0;i<(n-8)/7;++i)
				printf("8");
			printf("\n");
			continue;
		}
		dfs(0,0,n/8+1);
		printf("%s\n",str1);
	}
	return 0;
}
