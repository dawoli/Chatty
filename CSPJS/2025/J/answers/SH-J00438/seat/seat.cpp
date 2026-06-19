#include<iostream>
#include<algorithm>
using namespace std;
using i64=long long;
const int N=15;
int n,m;
int a[N*N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int scoreR;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (i==1) scoreR=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	//先枚举列 再枚举行
	bool flag=0;
	int cur=0; //当前是第几个人 
	for (int j=1;j<=m;j++)
	{
		if (j&1) //奇数列 向下
		{
			for (int i=1;i<=n;i++)
			{
				if (a[++cur]==scoreR)
				{
					flag=1;
					cout<<j<<' '<<i<<"\n";
					break;
				}
			}
		}else
		{
			for (int i=n;i>=1;i--)
			{
				if (a[++cur]==scoreR)
				{
					flag=1;
					cout<<j<<' '<<i<<"\n";
					break;
				}
			}
		}
		if (flag)	break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

