#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,t[500005],sum,z;
struct node1
{
	int l,r,d;
}b[1000005];
struct node2
{
	int cl,cr;
}c[1000005];
bool cmp(node1 x,node1 y)
{
	return x.d<y.d;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)cin >> a[i];
	for(int i = 1;i <= n;i ++)
	{
		int x=a[i];
		if(a[i]==k)
		{
			ans++;
			b[ans].l=i;
			b[ans].r=i; 
			b[ans].d=0;
			//cout << a[i]<<endl;
			continue;
		}
		for(int j = i+1;j <= n;j ++)
		{
			x=x^a[j];
			if(x==k)
			{
				ans++;
				b[ans].l=i;
				b[ans].r=j; 
				b[ans].d=j-i;
				//cout << a[j]<<endl;
				break;
			}
		}
	}
	sort(b+1,b+n+1,cmp);
	for(int i = 1;i <= ans;i ++)
	{
		bool p = true;
		for(int j = 1;j <= z;j ++)
		{
			if(b[i].r<c[j].cl||b[i].l>c[j].cr)continue;
			p=false;
			break;
		}
		if(p)
		{
			z++;
			c[z].cl=b[i].l;
			c[z].cr=b[i].r;
			sum++;
		}
	}
	cout << sum;
	return 0;
}
