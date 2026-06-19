#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[b]=s[i]-48;
			b++;
		}
	}
	for(int i=1;i<b;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]>a[j])
			{
				int x;
				x=a[i];
				a[i]=a[j];
				a[j]=x;
				i--;
			}
		}
	}
	for(int i=0;i<b;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
