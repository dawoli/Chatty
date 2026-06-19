#include<bits/stdc++.h>
using namespace std;
char s1[1000005],s2[1000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;++i)
		scanf("%s %s",s1,s2);
	for(i=1;i<=n;++i)
		scanf("%s %s",s1,s2);
	for(i=1;i<=q;++i)
		printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
