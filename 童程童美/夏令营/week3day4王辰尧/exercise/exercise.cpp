#include<iostream>
#include<string>
using namespace std;
string a[4010];
int main()
{
	freopen("exercise.in","r",stdin);
	freopen("exercise.out","w",stdout);
	int l=2005,r=2005,n,k;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k==0)
		{
			cin>>a[--l];
		}
		if(k==1)
		{
			cin>>a[++r];
		}
	}
	for(int i=r;i>=l;i--)if(a[i]!="")cout<<a[i]<<endl; 
}
