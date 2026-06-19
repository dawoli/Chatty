#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;

int a[1000005];
bool cmp(int a,int b)
{
	return a>=b;
}
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int cnt=1;
	for(int i=0;s[i]!='\0';i++)
	{
		if(48 <= s[i] && s[i] <= 57)
		{
			a[cnt]=int(s[i])-48;
			cnt++;
		}
	}
	cnt--;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout << a[i];
	}
	
	
	return 0;
}
