#include<bits/stdc++.h>
using namespace std;
int t,n,a,sum=0;
bool check(int x)
{
	if(x%2!=0)return 1;
	return 0;
}
int main()
{
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			if(check(a))sum++;
		}
		if(sum==0)cout<<"No"<<endl;
		else if(!check(sum))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
