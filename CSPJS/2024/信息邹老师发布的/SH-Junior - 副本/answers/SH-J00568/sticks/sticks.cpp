#include<bits/stdc++.h>
using namespace std;
int a[16]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0;
		cin>>n;
		while(n>14)
		{
			n-=7;
			sum++;
		}
		cout<<a[n];
		for(int i=0;i<sum;i++)
			cout<<8;
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
