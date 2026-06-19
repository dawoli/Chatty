#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	int a[15] = {6,2,5,5,4,5,6,3,7,6};
	int ans[100005] = {};
	for(int i=1;i<= 100000;i++)
	{
		string h = to_string(i);
		for(int j=0;j<h.length();j++)
		{
			ans[i] += a[h[j]-'0'];
		}
	}
	for(int i=1;i<=t;i++)
	{
		bool flag = false;
		cin>>n;
		for(int j=1;j<=10000;j++)
		{
			if(n==ans[j])
			{
				cout<<j<<endl;
				flag = true;
				break;
			}
		}
		if(flag==false)
		{
			cout<<-1<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
