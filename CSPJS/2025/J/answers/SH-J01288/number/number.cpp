#include <bits/stdc++.h>
using namespace std;
string Str;
int Num[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>Str;
	for(int i=0;i<Str.size();i++)
	{
		if(Str[i]>='0'&&Str[i]<='9')
		{
			Num[Str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=Num[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
