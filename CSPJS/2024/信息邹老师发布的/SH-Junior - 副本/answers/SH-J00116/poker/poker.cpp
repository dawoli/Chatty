#include<bits/stdc++.h>
using namespace std;
char b[54];
char h[54];
int n,sum,summ;
char a,c;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	sum=52;
	bool f=0;
	for(int i=0;i<n;i++)
	{
		f=0;
		cin>>a>>c;
		if(i==0)
		{
			b[summ]=a;
			h[summ]=c;
		} 
		for(int j=0;j<strlen(b);j++)
		{
			if(a==b[j] && c==h[j])	f=1;
		}
		if(f==0)
		{
			summ++;
			b[summ]=a;
			h[summ]=c;
		}
	}
	cout<<sum-strlen(b);
	return 0; 
}
