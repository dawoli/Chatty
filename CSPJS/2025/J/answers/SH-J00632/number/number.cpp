#include<bits/stdc++.h>
using namespace std;
string a;
long long ans[10]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> a;
	for(int i=0;i<a.size();i++)
	{
		if('0'<=a[i] && a[i]<='9')
		{
			ans[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(long long int j=1;j<=ans[i];j++)
		printf("%d",i);
	}
	return 0;
}
