#include<iostream>
using namespace std;
using i64=long long;
const int N=5e3+5,MOD=998'244'353;
int n;
int a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int res=0;
	for (int j=0;j<(1<<n);j++)
	{
		int ma=0,sum=0;
		for (int i=1;i<=n;i++)
		{
			if (1<<(i-1)&j)
			{
				ma=max(ma,a[i]);
				sum+=a[i];
			}
		}
		if (sum>ma*2)
		{
			(res+=1)%=MOD; 
		}
	}
	cout<<res<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

