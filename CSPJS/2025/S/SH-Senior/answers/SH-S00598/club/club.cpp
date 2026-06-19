#include<bits/stdc++.h>
using namespace std;

struct Point{
	int val, no, num;
}a[300005];

bool cmp(Point a, Point b)
{
	if(a.val>b.val)return true;
	return false;
}

bool used[100005];
int zl[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		memset(used, 0, 100005);
		zl[1]=zl[2]=zl[3]=0;
		int n;
		cin>>n;
		for(int i=1; i<=n*3; i++)
		{
			cin>>a[i].val;
			a[i].no=(i-1)/3+1;
			a[i].num=(i-1)%3+1;
		}
		sort(a+1, a+1+3*n, cmp);
		for(int i=1; i<=n; i++)
		{
			if(used[a[i].no]==false&&zl[a[i].num]<n/2)
			{
				ans+=a[i].val;
				used[a[i].no]=true;
				zl[a[i].num]++;
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}

