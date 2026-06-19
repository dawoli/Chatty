#include <bits/stdc++.h>
using namespace std;
struct Node{
	int num,last;
	long long sum;
}a[200002][2];
int T,n,ans;
int b[1000001];
int main()
{
	ios::sync_with_stdio(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0].num;
			a[i][1].num=a[i][0].num;
			a[i][0].last=b[a[i][0].num];
			a[i][1].last=b[a[i][1].num];
			b[a[i][0].num]=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][0].last==0)
			{
				a[i][0].sum=max(a[i-1][0].sum,a[i-1][1].sum);
				a[i][1].sum=max(a[i-1][0].sum,a[i-1][1].sum);
				cout<<a[i][0].sum<<" "<<a[i][1].sum<<endl;
				continue;
			}
			a[i][0].sum=max(a[a[i][0].last][0].sum+a[i][0].num+a[i-1][1].sum-a[a[i][0].last][1].sum,max(a[i-1][0].sum,a[i-1][1].sum));
			a[i][1].sum=max(a[a[i][1].last][1].sum+a[i][1].num+a[i-1][0].sum-a[a[i][0].last][0].sum,max(a[i-1][0].sum,a[i-1][1].sum));
			cout<<a[i][0].sum<<" "<<a[i][1].sum<<endl;
		}
		cout<<max(a[n][0].sum,a[n][1].sum)<<endl;
	}
	return 0;
}
