#include<iostream>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=(k<=1 ? 1 : 0);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]>1) flag=0;
	}
	//只有0或1的情况
	if (flag)
	{
		if (k==1)
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				if (a[i]==1)
				{
					cnt++;
				}
			}
			cout<<cnt<<"\n"; 
		}else
		{
			int res=0;
			bool tmp=0; //前1个1是否被占用 
			for (int i=1;i<=n;i++)
			{
				if (a[i]==0)
				{
					res++;
					tmp=0;
				}else if (a[i]==1 && a[i-1]==1 && !tmp)
				{
					tmp=1;
					res++;
				}else
				{
					tmp=0;
				}
			}
			cout<<res<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
