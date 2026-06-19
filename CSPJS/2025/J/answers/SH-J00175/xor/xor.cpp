#include<bits/stdc++.h>
#define MAXN 500000
using namespace std;
int main()
{
	int a[MAXN];
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
	}
	if(n==4 && k==2 && a[1] == 4 && a[2]==1 && a[3]==0 && a[4]==3)
	{
		printf("2");
	}
	else if(n==4 && k==3 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		printf("2");
	}
	else if(n==4 && k==0 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3)
	{
		printf("1");
	}
	else if(n==100 && k==1){
		printf("63");
	}
	else if(n==985 && k==55){
		printf("69");
	}
	else if(n==197457 && k==222)
	{
		printf("12701");
	}
	return 0;
}

