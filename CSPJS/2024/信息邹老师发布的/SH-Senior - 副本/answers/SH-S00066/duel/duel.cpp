#include <bits/stdc++.h>
using namespace std;

int a[100005],b[100005],d[100005];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,mx=0;
	cin >> n;
	for(int i=1,x;i<=n;i++)
	{
		cin >> x;
		d[x]++;
		mx=max(mx,x);
	}
	int top=0;
	for(int i=1;i<=mx;i++)
	{
		if(d[i]>0)
		{
			top++;
			a[top]=d[i];
			b[top]=d[i];
		}
	}
	int l=1,r=2,c=0;
	while(c<=mx*2)
	{
		if(a[l]>0)
		{
			if(b[r]>=a[l])
			{
				b[r]=a[r]-a[l];
				a[l]=0;
				b[l]=0;
			}
			if(b[r]<a[l])
			{
				a[l]-=b[r];
				b[r]=0;
				b[l]=0;
			}
			l++,r++;
		}
		if(a[r]==0&&a[l]>0)
		{
			r++;
		}
		else if(a[l]==0&&l+1==r)
		{
			r++;
			l++;
		}
		else if(a[l]==0&&l+1<r)
		{
			l++;
		}

		c++;
	}
	int cnt=0;
	for(int i=1;i<=mx;i++)
	{
		cnt+=a[i];
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
