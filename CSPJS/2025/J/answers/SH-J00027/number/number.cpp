#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],ls;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	cin>>s;
	ls=s.size();
	long long n=1;
	for(int i=0;i<ls;i++) 
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
	n-=1;//现在n是a数组的长度 
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
