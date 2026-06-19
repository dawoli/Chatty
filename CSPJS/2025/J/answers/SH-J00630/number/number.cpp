#include<bits/stdc++.h>
using namespace std;
int a[1000000];
string m;


int main()
{int sum=0;
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	string	s;
	cin>>s;
	for(int i=0;i<=s.length()-1;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			sum++;
			a[sum]=s[i]-'0';
			
		}
	}
	
	for(int i=1;i<=sum;i++)
	{int temp =0;
		if(a[i]<=a[i+1])
		{
		temp=a[i];
		a[i]=a[i+1];
		a[i+1]=temp;	
		}
	}
	for(int i=1;i<=sum;i++)
	cout<<a[i];
	
	return 0;
}
