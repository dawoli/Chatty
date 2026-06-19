#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long e,f,g,c,d,h,j,k,l,m,e1,f1,g1,c1,d1,h1,j1,k1,l1,m1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
string s;
cin>>s;
char t='a',p='z';
int n=s.size();
long num[n];
for(int i=0;i<n;i++)
{
	if(s[i]>=t&&s[i]<=p)continue;
	if(s[i]=='1')
		{
		num[i]=1; e++;
	}
	if(s[i]=='2')
	{
		num[i]=2;f++;
	}
	if(s[i]=='3')
	{
		num[i]=3;g++;
	}
	if(s[i]=='4')
	{
		num[i]=4;c++;
	}
	if(s[i]=='5')
	{
		num[i]=5;d++;
	}
	if(s[i]=='6')
	{
		num[i]=6;h++;
	}
	if(s[i]=='7')
	{
		num[i]=7;j++;
	}
	if(s[i]=='8')
	{
		num[i]=8;k++;
	}
	if(s[i]=='9')
	{
		num[i]=9;l++;
	}
	if(s[i]=='0')
	{
		num[i]=0;m++;
	}
}
sort(num,num+n);
for(int i=n-1;i>=0;i--)
{
	if(num[i]==1&&e1<e)
	{
		cout<<1; e1++;
	}
	if(num[i]==2&&f1<f)
	{
		cout<<2;f1++;
	}
	if(num[i]==3&&g1<g)
	{
		cout<<3;g1++;
	}
	if(num[i]==4&&c1<c)
	{
		cout<<4;c1++;
	}
	if(num[i]==5&&d1<d)
	{
		cout<<5;d1++;
	}
	if(num[i]==6&&h1<h)
	{
		cout<<6;h1++;
	}
	if(num[i]==7&&j1<j)
	{
		cout<<7;j1++;
	}
	if(num[i]==8&&k1<k)
	{
		cout<<8;k1++;
	}
	if(num[i]==9&&l1<l)
	{
		cout<<9;l1++;
	}
	if(num[i]==0&&m1<m)
	{
		cout<<0;m1++;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

