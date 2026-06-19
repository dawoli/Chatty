#include<bits/stdc++.h>
using namespace std;
int arr[1005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum;
	scanf("%d %d",&n,&m);
	sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		scanf("%d",&arr[i]);
	}
	int score=arr[1];
	sort(arr+1,arr+sum+1,cmp);
	int rk;
	for(int i=1;i<=sum;i++)
	{
		if(arr[i]==score)
		{
			rk=i;
			break;
		}
	}
	int lie=(int)ceil(rk*1.0/n);
	printf("%d ",lie);
	int typ;
	if(lie%2==0)
	{
		printf("%d\n",lie*n-rk+1);
	}
	else
	{
		printf("%d\n",n-(lie*n-rk));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
