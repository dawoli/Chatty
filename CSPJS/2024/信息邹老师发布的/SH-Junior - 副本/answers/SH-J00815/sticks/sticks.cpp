#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a;
	cin>>a;
	while(a)
	{
		long long f[100010]={0,0,1,7,4,2,6,8,10};
		int n;
		cin>>n;
		f[0]=-1,f[1]=-1;
		for(int i=9;i<=n;i++)
		{
			f[i]=min(min(min(min(min(f[i-2]*10+1,f[i-3]*10+7),f[i-4]*10+4),f[i-5]*10+2),f[i-6]*10),f[i-7]*10+8);
		}
		cout<<f[n]<<endl;
		a--;
	}
	
	return 0;
}
