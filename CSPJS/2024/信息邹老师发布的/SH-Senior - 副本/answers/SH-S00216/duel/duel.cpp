#include<bits/stdc++.h>
using namespace std;
int n,ans,num,cnt;
int a[1000001],b[1000001];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(b[i] > 0)
		{
			ans = b[i];
			num = i;
			break;
		}
	}
	for(int i=num+1;i<=100000;i++)
	{
		if(b[i] > 0)
		{
			if(b[i] >= ans)
			{
				cnt += ans;
				ans = b[i];
			}
			if(b[i] < ans) cnt += b[i];
		}
	}
	cout << n-cnt << endl;
	return 0;
}  

