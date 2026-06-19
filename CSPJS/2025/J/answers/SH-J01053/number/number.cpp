#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];
int k;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>47&&s[i]<59)
		{
			a[++k]=s[i]-'0';
		}	
	}
	sort(a+1,a+k+1);
	if(a[k]==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=k;i>=1;i--)
		{
			cout<<a[i];
		}
	}
	return 0;
}
