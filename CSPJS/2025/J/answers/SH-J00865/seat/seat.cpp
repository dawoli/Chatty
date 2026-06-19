#include<bits/stdc++.h>
using namespace std;
const int MAXN=100,MOD=0;
int n,m,a[MAXN+5];
bool cmp(int n1,int n2)
{
	return n1>n2;
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
int main()
{
	init();
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1],t2;
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==t)
		{
			t2=i;
			break;
		}
	}
	int col=(t2+n-1)/n,t3=t2-(col-1)*n,raw=(col&1?t3:n-t3+1);
	cout<<col<<' '<<raw;
	return 0;
}
