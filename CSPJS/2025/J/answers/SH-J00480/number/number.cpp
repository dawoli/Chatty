#include<bits/stdc++.h>
using namespace std;
char s[2000006];
int arr[2000006],arr_l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int i,l=strlen(s+1);
	for(i=1;i<=l;++i)
	{
		if(s[i]>='0'&&s[i]<='9')
			arr[++arr_l]=s[i]-'0';
	}
	sort(arr+1,arr+arr_l+1);
	if(arr[arr_l]==0)
		printf("0\n");
	else
	{
		for(i=arr_l;i>=1;--i)
			printf("%d",arr[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
