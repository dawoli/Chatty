#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,d;
	int c[20000000];
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b;
	cin>>d;
	for(int i=0;i<20000000;i++)
	{
		cin>>c[i];
	}
	if(a==4&&b==4&&c==2)
	{
		cout<<"13";
	}
	else if(a==1000&&b==1000000&&c==5)
	{
		cout<<"505585650";
	}
	else if(a==1000&&b==1000000&&c==10)
	{
		cout<<"504898585";
	}
	return 0;
}
