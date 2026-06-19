#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long num[5];
}a[100005];
int t,n;
bool cmp1(Node x,Node y){ return x.num[1]>y.num[1]; }
bool cmp2(Node x,Node y){ return x.num[2]>y.num[2]; }
bool cmp3(Node x,Node y){ return x.num[3]>y.num[3]; }
long long func(int x)
{
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		if(i<=n/2) res+=a[i].num[x];
		else 
		{
			if(x==1) res+=max(a[i].num[2],a[i].num[3]);
			if(x==2) res+=max(a[i].num[1],a[i].num[3]);
			if(x==3) res+=max(a[i].num[1],a[i].num[2]);
		}
	}
	return res;
}
void solveA()
{
	sort(a+1,a+1+n,cmp1);
	long long ans=0;
	for(int i=1;i<=n/2;i++) ans+=a[i].num[1];
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool A=1;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i].num[1]>>a[i].num[2]>>a[i].num[3];
			if(a[i].num[3]!=0||a[i].num[2]!=0) A=0;
		}
		if(A==1) 
		{
			solveA();
			return 0;
		}
		long long ans=0;
		sort(a+1,a+1+n,cmp1);
		ans=func(1);
		sort(a+1,a+1+n,cmp2);
		ans=max(ans,func(2));
		sort(a+1,a+1+n,cmp3);
		ans=max(ans,func(3));
		cout<<ans<<endl;
	}
	return 0;
} 

