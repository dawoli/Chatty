#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],c[100001],k;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)	scanf("%d",&c[i]);
	while((pow(2,k))<n)	k++;
	printf("pwq\n");
	return 0;
}
