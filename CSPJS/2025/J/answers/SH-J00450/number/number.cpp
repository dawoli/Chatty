#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char c[1000005];
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	int i,n=strlen(c),j=0;
	for(i=0;i<n;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[j++]=c[i]-'0';
		}
	}
	sort(a,a+j);
	for(i=j-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
