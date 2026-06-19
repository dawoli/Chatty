#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string a[10]={};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<52-n;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
