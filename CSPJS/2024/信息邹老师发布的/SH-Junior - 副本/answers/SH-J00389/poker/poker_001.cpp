#include<bits/stdc++.h>
using namespace std;
int n,sum,b[1000][1000];
char a[1000][2];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
		if(b[a[i][1]][a[i][2]]==0)
		{
			sum++;
		}
		b[a[i][1]][a[i][2]]++;
	}
	cout<<52-sum;
	return 0;
}
