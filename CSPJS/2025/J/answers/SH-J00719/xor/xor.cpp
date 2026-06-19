#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
const int N=5e5+10;
const int M=1048586;
int cnt=0;
int a[N];
struct node{
	int l,r;
}p[N];

bool cmp(node x,node y)
{
	if(x.r==y.r)
	{
		return x.l<y.l;
	}
	return x.r<y.r;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("xor6.in","r",stdin);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	if(n<=10000)
//	{
		for(int i=1;i<=n;i++)
		{
			int ck=0;
			for(int j=i;j<=n;j++)
			{
				ck^=a[j];
				if(ck==k)
				{
					p[++cnt].l=i;
					p[cnt].r=j;
					break;
				}
			}
		}
		if(cnt==0)
		{
			cout<<0;
			return 0;
		}
		int ans=1;
		sort(p+1,p+cnt+1,cmp);
		int alr=p[1].r;
		int i=1;
		while(i<=cnt)
		{
			while(i<=cnt&&p[i].l<=alr) i++;
			if(i==cnt+1)
			{
				break;
			}
			ans++;
			alr=p[i].r;
		}
		cout<<ans;
//	}
//	else{
//		
//	}
	return 0;
}
