#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
char ll[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,s_l,t;
	scanf("%s",ll);
	s_l=strlen(ll);
	for(i=0;i<s_l;++i)
	{
		if(ll[i]>='0'&&ll[i]<='9')
			arr[++arr[0]]=ll[i]-'0';
	}
	sort(arr+1,arr+1+arr[0],greater<int>());
	for(i=1;i<=arr[0];++i)
		printf("%d",arr[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
