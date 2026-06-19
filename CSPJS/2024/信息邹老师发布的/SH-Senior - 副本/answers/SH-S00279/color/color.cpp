#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T,n;
int a[N],col[N];
int lowbit(int x)
{
	return x & (-x);
}
void work(int num)
{
	while(num > 0)
	{
		int lb = lowbit(num);
		col[(int)log2(lb) + 1] = 1;
		num -= lb;
	}
}
int cal()
{
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
			if(col[i] == col[j])
			{
				if(a[i] == a[j])
					ans += a[i];
				break;
			}
	}
	return ans;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T --)
	{
		memset(col,0,sizeof(col));
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		if(n <= 15)//SPJ1
		{
			int cnt = 0;
			for(int i=0;i<=(1<<n)-1;i++)
			{
				memset(col,0,sizeof(col));
				work(i);
				cnt = max(cnt,cal());
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
