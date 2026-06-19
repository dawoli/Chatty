#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005]={0},len=0,j=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=a[i]-'0';
			j+=1;
		}
	}
	sort(b,b+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
