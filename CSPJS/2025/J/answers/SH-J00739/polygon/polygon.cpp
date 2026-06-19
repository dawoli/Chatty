#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n;
long long c,num=0;
bool cmp(int a,int b)
{
	return a<b;
}
void ppp(int b,int i)
{
	
	if(i!=0)
	{
		i--;
		for(int x = b+1;x<n;x++)
		{
			num+=a[x];
			ppp(x,i);
			num-=a[x];
		}
		i++;
	}
	else if(num>a[b]*2)
		c++;
	
}
void pp(int n)
{
	for(int i = 3;i<=n;i++)
	{
		ppp(-1,i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	pp(n);
	cout << c%998244353 << endl;
	return 0;
}
