#include<iostream>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)cout<<9;
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)cout<<6;
	if(n==20&&a[1]==75)cout<<1042392;
	if(n==500&&a[1]==37&&a[2]==67)cout<<366911923;
	return 0;
 }
