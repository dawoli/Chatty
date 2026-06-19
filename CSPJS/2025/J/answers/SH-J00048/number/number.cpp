#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	cin >> a;
	int t=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			a[t]=a[i];
			t++;
		}
	}
	for(int i=1;i<t;i++)
	{
		for(int j=0;j<t-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	if(a[0]=='0')
	{
		cout << 0;
		return 0; 
	}
	for(int i=0;i<t;i++)
	{
		cout << a[i]-'0';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
