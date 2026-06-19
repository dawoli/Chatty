#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string poker[53];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,index1=0;
	bool p=true;
	string str;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		p=true;
		cin>>str;
		for(int i=1;i<=index1;i++)
		{
			if(str==poker[i])
			{
				p=false;
				break;
			}
		}
		if(p)
		{
			poker[++index1]=str;
		}
	}
	cout<<52-index1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
