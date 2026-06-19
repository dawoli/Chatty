#include<bits/stdc++.h>
using namespace std;
char str[1000005];
int arr[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,l=0;
	scanf("%s",str);
	for(i=0;i<strlen(str);++i)
	{
		if(str[i]>='0'&&str[i]<='9')
			arr[++l]=(int)(str[i]-'0');
	}
	sort(arr+1,arr+1+l);
	for(i=l;i>=1;--i)
		printf("%d",arr[i]);
	return 0;
}
