#include<bits/stdc++.h>
using namespace std;
string a;
int x[1000010]; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long j=1,size=a.size();
	for(int i=0;i<size;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			x[j]=a[i]-'0';
			j++;
		}
	}
	sort(x+1,x+1+j);
	for(int i=j;i>1;i--)
	{
		cout<<x[i];
	}
	return 0;
}

