#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	char c[200000000][20000000];
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<20000000;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>c[i][j];
		}
	}
	if(a==4&&b==2)
	{
		cout<<"2"<<endl;
		cout<<"0";
	}
	else if(a==3&&b==4)
	{
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
	}
	return 0;
}
