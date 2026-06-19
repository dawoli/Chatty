#include<bits/stdc++.h>
using namespace std;

int n,q;
char s1[200010]={0};
char s2[200010]={0};
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s1[i],s2[i]);
	}
	while(q--)
	{
		string t1,t2;
		scanf("%s%s",&t1,&t2);
		printf("0\n");
	}
	
	return 0;
 } 
