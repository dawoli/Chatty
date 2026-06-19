#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int num[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,l;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;++i)
		if(isdigit(s[i]))
			num[++num[0]]=s[i]-'0';
	sort(num+1,num+num[0]+1);
	for(i=num[0];i>=1;--i)
		printf("%d",num[i]);			
	fclose(stdin);
	fclose(stdout);
	return 0;
}
