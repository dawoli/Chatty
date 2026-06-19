#include<bits/stdc++.h>
using namespace std;
char str[1000005];
int cnt[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,i,j;
	scanf("%s",str+1);
	n=strlen(str+1);
	for(i=1;i<=n;++i)
		if(str[i]>='0'&&str[i]<='9')
			++cnt[str[i]-'0'];
	for(i=9;i>=0;--i)
		for(j=1;j<=cnt[i];++j)
			printf("%d",i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
