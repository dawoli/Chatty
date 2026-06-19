#include<iostream>
#include<string>
using namespace std;
int ans[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int i,j,n;
	n=a.size();
	for(i=0;i<n;i++)
	{
		if(a[i]>='0' && a[i]<='9')
			ans[int(a[i])-48]++;
	}
	for(i=9;i>=0;i--)
	{
		for(j=0;j<ans[i];j++)
			cout<<i;
	}
	return 0;
}
