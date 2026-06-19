#include<bits/stdc++.h>
using namespace std;
char str[1000005];
int arr[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str+1);
	int s_l=strlen(str+1);
	int pos=0;
	for(int i=1;i<=s_l;++i)
	{
		if(str[i]>='0'&&str[i]<='9')
			arr[++pos]=str[i]-'0';
	}
	sort(arr+1,arr+pos+1);
	for(int i=pos;i>=1;i--)
		printf("%d",arr[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
