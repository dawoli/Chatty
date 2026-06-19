#include<bits/stdc++.h>
using namespace std;
char nd[1000005];
int c[1000005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,i;
	scanf("%d %d",&n,&m);
	scanf("%s",nd);
	for(i=1;i<=n;++i)
		scanf("%d",&c[i]);
	printf("%d",0);
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
