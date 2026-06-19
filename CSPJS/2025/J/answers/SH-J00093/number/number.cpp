#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[1000],z=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i< s.length();i++)
	{
		if(s[i]<58)
		{
			a[z]=s[i]%48;
			z++;
		}
	}
	sort(a,a+z,cmp);
	for(int i=0;i<z;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
