#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int a[200001]={0};
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>=maxn)maxn=a[i];
		}
		cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
}
