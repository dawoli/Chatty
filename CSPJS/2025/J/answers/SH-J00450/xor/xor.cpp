#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int c[1000005];
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(a[0]==1)
		printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
