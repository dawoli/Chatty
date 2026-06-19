#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >>n>>k;
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
	}
	int sum = 0,cnt = 0;
	for(int i = 1;i < n;i++)
	{
		int j = i;
		sum = a[i];
		while(sum!=k&&j<=n)
		{
			sum = sum^a[++j];
		}
		if(sum==k){
			cnt++;
			i = j;
		}
	}
	cout <<cnt;
	return 0;
}
