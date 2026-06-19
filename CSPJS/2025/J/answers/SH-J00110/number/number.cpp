#include<iostream>
using namespace std;
int a[20];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		int x=s[i]-'0';
		if(x>=0&&x<=9)
		{
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
