#include <bits/stdc++.h>
using namespace std;

char s[100005];
int a[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l=0;
	while((s[l]>='a'&&s[l]<='z')||(s[l]>='0'&&s[l]<='9'))
	{
		l++;
	}
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout << i;

		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
