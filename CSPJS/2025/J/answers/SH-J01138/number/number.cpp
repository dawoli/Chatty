#include<iostream>
#include<cstring>
using namespace std;
int count[10];
string str;
int main()
{
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++)
	{
		count[i]=0;
	}
	getline(cin,str);
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0' && str[i]<='9')
			count[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(count[i])
		{
			for(int j=0;j<count[i];j++)
			{
				cout<<i;
			}
		}
	}
	cout<<endl;
	return 0;
}
