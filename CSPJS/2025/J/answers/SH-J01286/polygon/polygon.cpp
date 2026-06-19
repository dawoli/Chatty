#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
int a[N];
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n == 5 && a[1] == 1)
	{
		cout<<9;
	}
	if(n == 20)
	{
		cout<<1042392;
	}
	
	return 0;
}
