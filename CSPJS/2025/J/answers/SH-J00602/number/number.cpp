#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int arr[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if(s[i]>='0'&&s[i]<='9')
			arr[++arr[0]]=s[i]-'0';
	sort(arr+1,arr+1+arr[0],greater<int>());
	if(arr[1]==0)
		printf("0");
	else
	{
		for(int i=1;i<=arr[0];i++)
			printf("%d",arr[i]);
	}
	return 0;
}
