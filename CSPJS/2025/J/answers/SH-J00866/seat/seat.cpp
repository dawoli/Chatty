#include<bits/stdc++.h>
using namespace std;

int a[15][15],grade[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt++;
			cin >> grade[cnt];
		}
	}
	int h=grade[1];
	sort(grade+1,grade+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(grade[i]==h)
		{
			int l=(i+n-1)/n;
			cout << l << " ";
			if(l%2==1)
			{
				if(i%n!=0) cout << i%n;
				else cout << n;
			}
			else
			{
				if(i%n!=0) cout << n-i%n+1;
				else cout << 1;
			}
		}
	}
	
	return 0;
}
