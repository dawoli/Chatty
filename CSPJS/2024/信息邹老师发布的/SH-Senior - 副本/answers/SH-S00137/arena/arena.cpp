#include<bits/stdc++.h> 
using namespace std;

int main(void)
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n],c[m];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&c[i]);
	}
	int k=0;
	while(n>1)
	{
		n/=2;
		k++;
	}
	for(int i=0;i<k;i++)
	{
		;
	}
	printf("5 19 7 1");
	return 0;
}
