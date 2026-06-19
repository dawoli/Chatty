#include<bits/stdc++.h>
using namespace std;
string a[105];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<51<<endl;
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			if(a[i]==a[j])
				a[i]="";
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]!="")
			sum++;
	cout<<52-sum;
	return 0;	
} 
