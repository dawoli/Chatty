#include<bits/stdc++.h>
using namespace std;
string s;
string summ;
char a[1000005]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.length();
	long long t=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[t]=s[i];
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)
	{
		if(a[i]=='0')
		{
			summ+='0';
		}
		if(a[i]=='1')
		{
			summ+='1';
		}
		if(a[i]=='2')
		{
			summ+='2';
		}
		if(a[i]=='3')
		{
			summ+='3';
		}
		if(a[i]=='4')
		{
			summ+='4';
		}
		if(a[i]=='5')
		{
			summ+='5';
		}
		if(a[i]=='6')
		{
			summ+='6';
		}
		if(a[i]=='7')
		{
			summ+='7';
		}
		if(a[i]=='8')
		{
			summ+='8';
		}
		if(a[i]=='9')
		{
			summ+='9';
		}
		t--;
	}
	cout<<summ;
	return 0;
 } 
