#include<bits/stdc++.h>
using namespace std;
string s;
long long sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	char a[len]={};
	int j=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<a[i];
	}
	cout<<sum;
	return 0;
}
