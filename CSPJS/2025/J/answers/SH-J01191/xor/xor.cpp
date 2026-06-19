#include<bits/stdc++.h>
using namespace std;
int arr[500005];
int f[500005][2];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int N,K,i,num0=0,num1=0,j;
	scanf("%d %d",&N,&K);
	for(i=1;i<=N;++i)
	{
		scanf("%d",&arr[i]);
		num0+=(arr[i]==0);
		num1+=(arr[i]==1);
	}
	if(K==0&&num1==N)//特殊性质A：对于1<=i<=N，满足arr[i]=1且k=0（10分）//
		printf("%d",N/2);
	else if(K<=1&&num0+num1==N)//特殊性质B：对于1<=i<=N，满足arr[i]=0或1且k<=1（无法捞取）//
	{
		if(K==0)//num1和num0分开做//
			printf("%d",num1/2+num0/2+min(num1%2,num0%2));
		else if(K==1)
			printf("%d",min(num1,num0)+(N-min(num1,num0)*2)/2);
	}
	else
		printf("%d",N/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
